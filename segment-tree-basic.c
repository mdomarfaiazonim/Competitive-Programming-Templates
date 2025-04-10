//-------------Code Snippet on Segment tree sum query--------------------
const ll N=2e5+5;
vector<ll>v(N),tree(N*3);
void init(ll node,ll l,ll r){
    if(l==r){
        tree[node]=v[l];
        return;
    }
    ll left=node*2,right=node*2+1,mid=(l+r)>>1;
    init(left,l,mid);
    init(right,mid+1,r);
    tree[node]=tree[left]+tree[right];
}
void update(ll node,ll l,ll r,ll val,ll ind){
    if(l>ind || r<ind)return;
    if(l>=ind && r<=ind){
        tree[node]=val;
        return ;
    }
    ll left=node*2,right=node*2+1,mid=(l+r)>>1;
    update(left,l,mid,val,ind);
    update(right,mid+1,r,val,ind);
    tree[node]=tree[left]+tree[right];
}
ll query(ll node,ll l,ll r,ll i,ll j){
    if(l>j || r<i)return 0;
    if(l>=i && r<=j){
        return tree[node];
    }
    ll left=node*2,right=node*2+1,mid=(l+r)>>1;
    
    return query(left,l,mid,i,j)+query(right,mid+1,r,i,j);
}
//-----------------------------------------------------