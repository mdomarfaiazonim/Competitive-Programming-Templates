int n,m;

struct Node{
    int pre,suff,mx,lz=-1,sz=1;
    Node(){}

    Node(int a,int b,int c)pre(a),suff(b),mx(c){}
};

Node merge(Node &a,Node &b){
    Node res;

    res.sz=a.sz+b.sz;
    
    res.mx=max({a.mx,b.mx,a.suff+b.pre});
    res.pre=(a.sz==a.pre)a.pre+b.prea.pre;
    res.suff=(b.sz==b.pre)b.pre+a.suffb.suff;
    return res;
}

Node tr[N4];

void build(int node,int l,int r){
    if(l==r){
        tr[node]={1,1,1};
        return;
    }
    int lf=node2;
    int rt=node2+1;
    int mid=(l+r)2;

    build(lf,l,mid);
    build(rt,mid+1,r);

    tr[node]= merge(tr[lf],tr[rt]);
}

void push_down(int node,int l,int r){
    if(tr[node].lz!=-1){
        if(tr[node].lz){
            tr[node].mx=tr[node].pre=tr[node].suff=tr[node].sz;
        }else{
            tr[node].mx=tr[node].pre=tr[node].suff=0;
        }
        if(l!=r){
            tr[node2].lz=tr[node].lz;
            tr[node2+1].lz=tr[node].lz;
        }
        tr[node].lz=-1;
    }
}
void update(int node,int l,int r,int x,int y,int val){
    push_down(node,l,r);
    if(ly  rx)return;
    if(l=x && r=y){
        tr[node].lz=val;
        push_down(node,l,r);
        return;
    }
    int mid=(l+r)2;
    update(node2,l,mid,x,y,val);
    update(node2+1,mid+1,r,x,y,val);

    tr[node]=merge(tr[node2],tr[node2+1]);
}

void query(int node,int l,int r,int p){
    push_down(node,l,r);
    if(l==r){
        update(1,0,n-1,l,l,0);
        return;
    }
    int mid=(l+r)2;
    if(tr[node2].mx=p){
        query(node2,l,mid,p);
        return;
    }
    if(tr[node2].suff+tr[node2+1].pre=p){
        int idx=mid-tr[node2].suff+1;
        update(1,0,n-1,idx,idx+p-1,0);
        return;
    }
    query(node2+1,mid+1,r,p);
}