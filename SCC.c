
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
const ll N = 2e5+5;
const ll INF = 1e17;

bool isvalid(int i, int j, int n, int m) { return (i >= 0 && j >= 0 && i < n && j < m); }

// Code on Strongly connected component and condensation graph
/*
  "Kosaraju's Algorithm"

  1) Sort all the vertices according to finishing time. (dfs1)
  2) Reverse the edges  (adjT)
  3) start the dfs again  (dfs2)
  4) Directed graph Hoite hobe must

*/
void dfs1(int ver,vll &vis,vector<vll>&adj,vll &order){
    vis[ver]=1;

    for(auto to : adj[ver]){
        if(!vis[to]){
            dfs1(to,vis,adj,order);
        }
    }
    order.pb(ver);
}

void dfs2(int ver,vll &vis,vector<vll>&adjT,vll &components){
    vis[ver]=1;
    components.pb(ver);

    for(auto to : adjT[ver]){
        if(!vis[to]){
            dfs2(to,vis,adjT,components);
        }
    }

}
int main() {
    int n;
    // ... read n ...
    fast_n_furious
    vector<vll>adj,adj_rev(n);
    vll root_nodes;

    for (;;) {
        int a, b;
        // ... read next directed edge (a,b) ...
        adj[a].push_back(b);
        adj_rev[b].push_back(a);
    }
    vll vis(n,0);
    vll root(n);
    vll order;

    for (int i = 0; i < n; i++)
        if (!vis[i])
            dfs1(i,vis,adj,order);

    vis.assign(n, false);
    reverse(order.begin(), order.end());

    for (auto v : order){
        if (!vis[v]) {
            vll component;
            dfs2 (v,vis,adj_rev,component);

            //For condensational part->
            ll roots=component.front();   
            root_nodes.pb(roots);
            for(auto u : component)root[u]=roots;

            // ... processing next component ...

            component.clear();
        }
    }
    /*
    for (int v = 0; v < n; v++)
    for (auto u : adj[v]) {
        int root_v = roots[v],
            root_u = roots[u];

        if (root_u != root_v)
            adj_scc[root_v].push_back(root_u);
    }

Here, we have selected the root of each component as the first node in its list.
This node will represent its entire SCC in the condensation graph.
roots[v] indicates the root node for the SCC to which node v belongs.
root_nodes is the list of all root nodes (one per component) in the condensation graph.

adj_scc is the adjacency list of the root_nodes. We can now traverse on adj_scc as our condensation graph, using only those nodes which belong to root_nodes.
    */
        
}
