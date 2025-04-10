
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
typedef vector<ll> vll;
#define S second
#define F first
#define fout(x) fixed << setprecision(x)
#define mem(arr, val) memset(arr, val, sizeof(arr))
#define lb lower_bound
#define ub upper_bound
#define FF(v, i) for (auto &i : v)
#define V2(dp, sz, sz2, val) vector<vector<ll>> dp(sz, vector<ll>(sz2, val))

#define getbit(n, i) (((n) & (1LL << (i))) != 0)
#define setbit0(n, i) ((n) & (~(1LL << (i))))
#define setbit1(n, i) ((n) | (1LL << (i)))
#define togglebit(n, i) ((n) ^ (1LL << (i)))
#define lowetset(n) ((n) & (-(n)))
#define rmv_last(n) (n & (n - 1))

const ll INF = 1e17;
const ll SZ = 2e5 + 1;

bool isvalid(int i, int j, int n, int m) { return (i >= 0 && j >= 0 && i < n && j < m); }
bool SC(pair<ll, ll> &a, pair<ll, ll> &b) { return (a.F != b.F) ? (a.F < b.F) : (a.S > b.S); } // F=> Ascending; S=> Descending
// More On segment tree

struct SegmentTree
{
    ll prefixSum, suffixSum, Sum, maxSum;
};

SegmentTree tree[SZ << 3];
ll par[SZ];
SegmentTree merge(SegmentTree a, SegmentTree b)
{
    SegmentTree res;

    res.Sum = a.Sum + b.Sum;

    res.maxSum = max(max(a.maxSum, b.maxSum), (a.suffixSum + b.prefixSum));

    res.prefixSum = max(a.prefixSum, a.Sum + b.prefixSum);

    res.suffixSum = max(b.suffixSum, b.Sum + a.suffixSum);

    return res;
}

void BUILD(ll node, ll start, ll end, vll &v)
{
    if (start == end)
    {
        ll X;
        X = v[start];
        
        par[start] = node ;
        tree[node].prefixSum = tree[node].suffixSum = tree[node].Sum = tree[node].maxSum = X;

        return;
    }

    ll l = node << 1;
    ll r = node << 1 | 1;

    ll mid = (start + end) >> 1;

    BUILD(l, start, mid, v);
    BUILD(r, mid + 1, end, v);

    tree[node] = merge(tree[l], tree[r]);
}

SegmentTree Query(ll node, ll start, ll end, ll x, ll y)
{
    if (start == x && end == y)
        return tree[node];

    ll l = node << 1;
    ll r = node << 1 | 1;

    ll mid = (start + end) >> 1;

    if (y <= mid)
        return Query(l, start, mid, x, y); // whole side is in left

    else if (x > mid)
        return Query(r, mid + 1, end, x, y); // whole side is in right

    else
    {
        return merge(Query(l, start, mid, x, mid), Query(r, mid + 1, end, mid + 1, y)); // split in two side so merging
    }
}
void Update(ll ind , ll val )
{
    ll node = par[ind];

    tree[node].prefixSum = tree[node].suffixSum = tree[node].Sum = tree[node].maxSum = val ;

    node >>= 1 ;

    while( node > 0 ) {
        ll l = node<<1 ;
        ll r = node<<1|1;
        tree[ node ] = merge( tree[l] , tree[r] );
        node >>= 1 ;
    }
}
// ends
int main()
{
    fast_n_furious

        int t = 1;
    // cin >> t;
    while (t--)
    {
    }
}
