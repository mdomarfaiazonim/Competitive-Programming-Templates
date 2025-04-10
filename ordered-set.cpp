
//         MOHAMMED OMAR FAIAZ ONIM
//         戦え

#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp> // Use codeblocks 
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
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
typedef long long ll;
typedef vector<ll> vll;
#define S second
#define F first
#define fout(x) fixed << setprecision(x)
#define mem(arr, val) memset(arr, val, sizeof(arr))



#define getbit(n, i) (((n) & (1LL << (i))) != 0)
#define setbit0(n, i) ((n) & (~(1LL << (i))))
#define setbit1(n, i) ((n) | (1LL << (i)))
#define togglebit(n, i) ((n) ^ (1LL << (i)))
#define lowetset(n) ((n) & (-(n)))
#define rmv_last(n) (n & (n - 1))

const ll mod = 1e9 + 7;
const ll INF = 1e17;

bool isvalid(int i, int j, int n, int m) { return (i >= 0 && j >= 0 && i < n && j < m); }
bool SC(pair<ll, ll> &a, pair<ll, ll> &b) { return (a.F != b.F) ? (a.F < b.F) : (a.S > b.S); } // F=> Ascending; S=> Descending

int main()
{
    fast_n_furious

        int t = 1;
    // cin >> t;
    while (t--)
    {
        ordered_set os;
    }
}
