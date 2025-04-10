
//         author : MOHAMMED OMAR FAIAZ ONIM
//         gmail : u2104029@student.cuet.ac.bd
//         戦え

#include <bits/stdc++.h>
#define pb push_back
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
typedef long double lld;
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
#define f(i, n, x) for (int i = 0 + x; i < n + x; i++)
#define cn cout << "\n";

#define getbit(n, i) (((n) & (1LL << (i))) != 0)
#define setbit0(n, i) ((n) & (~(1LL << (i))))
#define setbit1(n, i) ((n) | (1LL << (i)))
#define togglebit(n, i) ((n) ^ (1LL << (i)))
#define lowestset(n) ((n) & (-(n)))
#define rmv_last(n) (n & (n - 1))

const ll mod = 1e9 + 7;
const ll N = 2e5 + 5;
const ll INF = 1e18;

bool isvalid(int i, int j, int n, int m) { return (i >= 0 && j >= 0 && i < n && j < m); }

ll bigmod(ll b, ll p, ll m)
{ // b ^ p % m
    if (p == 0)
        return 1;
    if (p % 2 == 0)
    {
        ll x = bigmod(b, p / 2, m) % m;
        return (x * x) % m;
    }
    else
        return (b % m * bigmod(b, p - 1, m)) % m;
}
ll gcd(ll a, ll b)
{ // assuming a>=b
    return b == 0 ? a : gcd(b, a % b);
}
ll lcm(ll a, ll b)
{
    return (a / gcd(a, b)) * b * 1LL; // prevents overflow
}
ll inv_mod(ll a, ll m) { return bigmod(a, m - 2, m); }
// Using Fermat's theorem -> a^-1 ≡ a^(m-2) (mod m) where gcd(a,m)==1.

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif

void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.first); cerr << ","; _print(p.second); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}


int n, l;
vector<vector<int>> adj;

int timer;
int tin[N];
int tout[N];
int up[N][30];
void dfs(int v, int p,int ds)
{
    tin[v]=++timer;
    up[v][0] = p;
    for (int i = 1; i <= l; ++i)
        up[v][i] = up[up[v][i-1]][i-1];

    for (int u : adj[v]) {
        if (u != p)
            dfs(u, v,ds+1);
    }

    tout[v] = ++timer;
}

bool is_ancestor(int u, int v)
{
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

void preprocess(int root) {
    timer = 0;
    l = ceil(log2(n));
    dfs(root, root,0);
}
int main()
{
    fast_n_furious

#ifndef ONLINE_JUDGE
        freopen("Error.txt", "w", stderr);
#endif

    int testcases=1;
    // cin>>testcases;

    while(testcases--){

    }
}
