
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

ll n, m;
map<ll,vll>adj;
vector<ll> color;
vector<ll> parent;
ll cycle_start, cycle_end;

bool dfs(ll v)
{
    color[v] = 1;
    for (ll u : adj[v])
    {
        if (color[u] == 0)
        {
            parent[u] = v;
            if (dfs(u))
                return true;
        }
        else if (color[u] == 1)
        {
            cycle_end = v;
            cycle_start = u;
            return true;
        }
    }
    color[v] = 2;
    return false;
}

void find_cycle()
{
    color.assign(n, 0);
    parent.assign(n, -1);
    cycle_start = -1;

    for (ll v = 0; v < n; v++)
    {
        if (color[v] == 0 && dfs(v))
            break;
    }

    if (cycle_start == -1)
    {
        cout << "Acyclic" << endl;
    }
    else
    {
        vector<ll> cycle;
        cycle.push_back(cycle_start);
        for (ll v = cycle_end; v != cycle_start; v = parent[v])
            cycle.push_back(v);
        cycle.push_back(cycle_start);
        reverse(cycle.begin(), cycle.end());

        cout << "Cycle found: ";
        for (ll v : cycle)
            cout << v << " ";
        cout << endl;
    }
}
int main()
{
    fast_n_furious

        int t = 1;
    // cin >> t;
    while (t--)
    {
        // ll n;
        // cin >> n;

        // for (ll i = 1, u, v; i <= n; i++)
        // {
        //     cin >> u >> v;
        //     adj[u].pb(v);
        //     adj[v].pb(u);
        // }
        // vll par(n + 1);
        // col[1] = 1;
        // dfs(adj[1][0], 1, par);

        // for (auto i : cycles)
        // {
        //     for (auto j : i)
        //         cout << j << " ";
        //     cout << NN;
        // }
    }
}
