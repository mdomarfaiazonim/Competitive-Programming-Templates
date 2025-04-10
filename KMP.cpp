
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
/*
 To understand the template Watch this=>
 https://www.youtube.com/watch?v=sMARZCTPyNI&t=526s
*/
vll LPS(string &pat){
    vll pref(pat.size());

    ll i=1,j=0;

    while(i<pat.size()){

        if(pat[i]==pat[j]){
            pref[i]=j+1;
            j++;
        }else{
            if(j>0)j=pref[j-1],i--;
            else pref[i]=j;
        }
        i++;
    }

    return pref;
}
void KMP(string &text,string &pat){
    vll lps=LPS(pat);

    ll i=0,j=0,cnt=0;
    while(i<text.size()){
        if(text[i]==pat[j]){
            i++;
            j++;
        }else{
            if(j>0)j=lps[j-1];
            else i++;
        }
        if(j==pat.size()){
            cout<<"Found at index : "<<i-pat.size()<<NN;
            j=lps[j-1];
        }
    }
}
int main()
{
    fast_n_furious

        int t = 1;
    cin >> t;
    while (t--)
    {
        string text,pat;
        cin>>text>>pat;
        
    }
}
