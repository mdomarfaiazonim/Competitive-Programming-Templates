
//         MOHAMMED OMAR FAIAZ ONIM
//         戦え

#include <bits/stdc++.h>
#define pb push_back
#define NN "\n"
#define yes cout << "YES" \
                 << "\n";
#define no cout << "NO" \
                << "\n";
#define all(onim) onim.begin(), onim.end()
#define c(onim) cout << (onim) << NN;
#define fast_n_furious                \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
    
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<ll> vll;
typedef pair<ll,ll> pll;

#define S second
#define F first
#define fout(x) fixed << setprecision(x)
#define mem(arr, val) memset(arr, val, sizeof(arr))
#define lb lower_bound
#define ub upper_bound
#define V2(dp,sz,sz2,val) vector<vector<ll>>dp(sz,vector<ll>(sz2,val))

#define getbit(n, i) (((n) & (1LL << (i))) != 0)
#define setbit0(n, i) ((n) & (~(1LL << (i))))
#define setbit1(n, i) ((n) | (1LL << (i)))
#define togglebit(n, i) ((n) ^ (1LL << (i)))
#define lowestset(n) ((n) & (-(n)))
#define rmv_last(n) (n & (n - 1))

const ll mod = 1e9 + 7;
const ll INF = 1e17;

bool isvalid(int i, int j, int n, int m) { return (i >= 0 && j >= 0 && i < n && j < m); }

//-------------Code Snippet on Segment tree sum query--------------------
const ll N=30001;
vector<ll>tree(N*4,0);

struct Node{
    ll type,l,r,pos,qPos,val;
};
vector<Node>vec;
void update(ll node,ll l,ll r,ll val,ll ind){
    if(l>ind || r<ind)return;
    if(l>=ind && r<=ind){
        tree[node]+=val;
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
int main()
{
    fast_n_furious

        int t = 1;
    // cin >> t;
    while (t--)
    {
        ll n;
        cin>>n;
        for(int i=0;i<n;i++){
            ll x;
            cin>>x;
            Node temp;
            temp.type=1;
            temp.val=x;
            temp.pos=i;
            vec.pb(temp);
        }

        ll q;
        cin>>q;
        vll res(q+1);

        for(int i=0;i<q;i++){
            ll a,b,x;
            cin>>a>>b>>x;
            --a,--b;
            Node tmp;
            tmp.type=2;
            tmp.val=x;
            tmp.l=a,tmp.r=b;
            tmp.qPos=i;
            vec.pb(tmp);
        }

        sort(all(vec),[&](Node a,Node b){
            if(a.val!=b.val)return a.val>b.val;
            return a.type>b.type;
        });

        for(auto i : vec){
            if(i.type==1){
                update(1,0,n-1,1,i.pos);
            }else{
                res[i.qPos]=query(1,0,n-1,i.l,i.r);
            }
        }
        for(int i=0;i<q;i++)cout<<res[i]<<NN;
    }
}
