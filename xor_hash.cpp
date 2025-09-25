
//         author : MOHAMMED OMAR FAIAZ ONIM
//         gmail : u2104029@student.cuet.ac.bd
//         戦え

#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const int N = 5e5 + 5;
const long long INF = 1e18;
#define ll long long

auto random_address = []
{ char *p = new char; delete p; return uint64_t(p); };
const uint64_t SEED = chrono::steady_clock::now().time_since_epoch().count() * (random_address() | 1);
mt19937_64 rng(SEED);

static inline ll xor_hash(ll x)
{
    return rng();
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll testcases = 1;
    // cin>>testcases;

    while (testcases--)
    {

        using hash_t = uint64_t;

        ll n;
        cin >> n;

        vector<hash_t> hash(n + 1);

        for (int i = 0; i <= n; i++)
        {
            hash[i] = xor_hash(i);
        }
    }
}
