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
const ll INF = LLONG_MAX;
 
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
 
string s;
ll n;
ll p = 31, p2 = 53;
ll mod2 = 1e9 + 9;
ll H[N],poW[N];
ll H2[N],poW2[N];
 
ll calc(int l, int r){
    ll x = (H[r + 1] - H[l] + mod) % mod;
    x = (x * poW[n - l - 1]) % mod;
    return x;
}
ll calc2(int l, int r){
    ll x = (H2[r + 1] - H2[l] + mod2) % mod2;
    x = (x * poW2[n - l - 1]) % mod2;
    return x;
}
void generatePow(){
    poW[0]=poW2[0]=1;
    for(int i=1;i<n;i++){
        poW[i]=(poW[i-1]*p)%mod;
        poW2[i]=(poW2[i-1]*p2)%mod2;
    }
}

void generateHash(){
    for(int i=0;i<n;i++){
        H[i+1]=(H[i]+(s[i]-'a'+1)*poW[i])%mod;
        H2[i+1]=(H2[i]+(s[i]-'a'+1)*poW2[i])%mod2;
    }
}
int main()
{
    fast_n_furious
 
        int testcase = 1;
    // cin >> testcase;
    while (testcase--)
    {
        cin>>s;
        n=s.size();
 
        generatePow();
        generateHash();

    }
}