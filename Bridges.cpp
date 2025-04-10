
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
typedef pair<ll, ll> pll;

#define S second
#define F first
#define fout(x) fixed << setprecision(x)
#define mem(arr, val) memset(arr, val, sizeof(arr))
#define lb lower_bound
#define ub upper_bound
#define V2(dp, sz, sz2, val) vector<vll> dp(sz, vll(sz2, val))
#define V3(dp, sz, sz2, sz3, val) vector<vector<vll>> dp(sz, vector<vll>(sz2, vll(sz3, val)))
#define f(i, n) for (int i = 0; i < n; i++)
#define cn cout << "\n";

#define getbit(n, i) (((n) & (1LL << (i))) != 0)
#define setbit0(n, i) ((n) & (~(1LL << (i))))
#define setbit1(n, i) ((n) | (1LL << (i)))
#define togglebit(n, i) ((n) ^ (1LL << (i)))
#define lowestset(n) ((n) & (-(n)))
#define rmv_last(n) (n & (n - 1))

const ll mod = 1e9 + 7;
const ll N = 2e5 + 5;
const ll INF = 1e17;

bool isvalid(int i, int j, int n, int m) { return (i >= 0 && j >= 0 && i < n && j < m); }
void take(int n, vll &v, int start = 0)
{
    for (int i = start; i < n; i++)
        cin >> v[i];
}
void print(int n, vll &v, int start = 0)
{
    for (int i = start; i < n; i++)
        cout << v[i] << " ";
    cout << "\n";
}
ll tin[N], low[N], sz[N], vis[N];
unordered_map<ll, vll> adj;
ll timer, res;
ll n, m;
void dfs(int ver, int par = -1)
{
    tin[ver] = low[ver] = timer++;

    vis[ver] = sz[ver] = 1;

    for (auto to : adj[ver])
    {
        if (to == par)
            continue;

        if (!vis[to])
        {
            dfs(to, ver);
            sz[ver] += sz[to];
        }
        low[ver] = min(low[ver], low[to]);
    }
    if (low[ver] == tin[ver])
        res = max(res, sz[ver] * (n - sz[ver]));
}
// codeforces-  (F) Non-academic Problem div-3
int main()
{
    fast_n_furious

        int testcase = 1;
    cin >> testcase;
    while (testcase--)
    {

        cin >> n >> m;

        f(i, n + 5) tin[i] = low[i] = sz[i] = vis[i] = 0;

        adj.clear();

        for (int i = 1; i <= m; i++)
        {
            ll x, y;
            cin >> x >> y;
            adj[x].pb(y);
            adj[y].pb(x);
        }
        timer = 0;
        res = 0;
        dfs(1);
        c(n * (n - 1) / 2 - res)
    }
}
