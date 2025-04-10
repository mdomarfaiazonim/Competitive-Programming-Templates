
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
#define V2(dp,sz,sz2,val) vector<vll>dp(sz,vll(sz2,val))
#define V3(dp,sz,sz2,sz3,val) vector<vector<vll>>dp(sz,vector<vll>(sz2,vll(sz3, val)))
#define f(i,n) for(int i=0;i<n;i++)
#define cn cout<<"\n";

#define getbit(n, i) (((n) & (1LL << (i))) != 0)
#define setbit0(n, i) ((n) & (~(1LL << (i))))
#define setbit1(n, i) ((n) | (1LL << (i)))
#define togglebit(n, i) ((n) ^ (1LL << (i)))
#define lowestset(n) ((n) & (-(n)))
#define rmv_last(n) (n & (n - 1))

const ll mod = 1e9 + 7;
const ll N = 2e5+5;
const ll INF = 1e17;

bool isvalid(int i, int j, int n, int m) { return (i >= 0 && j >= 0 && i < n && j < m); }
void take(int n,vll &v,int start=0){
    for(int i=start;i<n;i++)cin>>v[i];
}
void print(int n,vll &v,int start=0){
    for(int i=start;i<n;i++)cout<<v[i]<<" ";
    cout<<"\n";
}
ll n,m;
struct Edge{
    ll a,b,c;
};
map<ll,vll>adj;

void dfs(int ver,vll &vis){
    vis[ver]=1;
    for(auto to  : adj[ver]){
        if(!vis[to])dfs(to,vis);
    }
}
vector<Edge>ve;
int main()
{
    fast_n_furious

        int testcase = 1;
    // cin >> testcase;
    while (testcase--)
    {
        cin>>n>>m;

        while(m--){
            ll a,b,c;
            cin>>a>>b>>c;

            ve.pb({a,b,c});
        }
        vll dist(n+1,INF);
        vll comps;
        vll vis(n+1);
        for(int i=1;i<=n;i++){
            if(!vis[i]){
                dfs(i,vis);
                comps.pb(i);
            }
        }
        for(auto to : comps)dist[to]=0;

        // dist[1]=0;
        ll fg=0;

        vll pt(n+1,-1);
        for(int i=0;i<n;i++){
            fg=0;
            for(auto e : ve){
                if(dist[e.a]<INF){
                    if(dist[e.b]>dist[e.a]+e.c){
                        fg=e.b;
                        dist[e.b]=max(dist[e.a]+e.c,-INF);
                        pt[e.b]=e.a;
                    }
                }
            }

            if(!fg)break;
        }
        if(!fg){
            no
            continue;
        }

        yes
        set<ll>st;
        ll cur=fg;
        deque<ll> res;

        while(1){
            res.pb(cur);
            if(st.count(cur))break;
            st.insert(cur);
            cur=pt[cur];
        }
        while(res.front()!=res.back())res.pop_front();
        reverse(all(res));
        for(auto to : res)cout<<to<<" ";
        cout<<NN;

    }
}
