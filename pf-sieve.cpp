
//         MOHAMMED OMAR FAIAZ ONIM
//        لا إله إلا الله محمد رسول الله

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

#define getbit(n, i) (((n) & (1LL << (i))) != 0)
#define setbit0(n, i) ((n) & (~(1LL << (i))))
#define setbit1(n, i) ((n) | (1LL << (i)))
#define togglebit(n, i) ((n) ^ (1LL << (i)))
#define lowetset(n) ((n) & (-(n)))
#define rmv_last(n) (n & (n - 1))

const ll mod = 1000003;
const ll INF = 1e17;

bool isvalid(int i, int j, int n, int m) { return (i >= 0 && j >= 0 && i < n && j < m); }
bool SC(pair<ll, ll> &a, pair<ll, ll> &b) { return (a.F != b.F) ? (a.F < b.F) : (a.S > b.S); } // F=> Ascending; S=> Descending
const ll MAXN = 1000000;
bitset<MAXN + 5> prime;
vll pn;
map<ll, ll> times;
void SieveOfEratosthenes(int n)
{
    // Create a boolean array "prime[0..n]" and initialize
    // all entries it as true. A value in prime[i] will
    // finally be false if i is Not a prime, else true.
    bool prime[n + 1];
    memset(prime, true, sizeof(prime));
 
    for (int p = 2; p * p <= n; p++) {
        // If prime[p] is not changed, then it is a prime
        if (prime[p] == true) {
            // Update all multiples of p greater than or
            // equal to the square of it numbers which are
            // multiple of p and are less than p^2 are
            // already been marked.
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
 
    // Print all prime numbers
    for (int p = 2; p <= n; p++)
        if (prime[p])
            cout << p << " ";
}
void primefact(ll n)
{
    for (ll i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            ll cnt = 0;
            while (n % i == 0)
            {
                times[i]++;
                n /= i;
            }
        }
    }
    if (n > 1)
        times[n] = 1;
}

ll modprod(ll a, ll b, ll m) { return ((a % m) * (b % m) * 1LL) % m; }
ll modsum(ll a, ll b, ll m) { return ((a % m) + (b % m)) % m; }
ll bigmod (ll b, ll p, ll m){  // b ^ p % m
    if (p==0) return 1;
    if (p%2==0) {
        ll x=bigmod(b, p/2, m)%m;
        return (x*x)%m;
    }
    else return (b%m * bigmod(b, p-1, m))%m;
}
ll gcd(ll a, ll b) { // assuming a>=b 
  return b == 0 ? a : gcd(b, a % b);
}
ll lcm(ll a,ll b){
    return (a/gcd(a,b))*b*1LL; //prevents overflow
}
ll inv_mod(ll a, ll m) {return bigmod(a, m-2, m);}

// Using Fermat's theorem -> a^-1 ≡ a^(m-2) (mod m) where gcd(a,m)==1.

int main()
{
    fast_n_furious

        int t = 1;
    // cin >> t;
    while(t--){
    }
}
