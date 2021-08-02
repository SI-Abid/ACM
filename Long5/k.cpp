#include "bits/stdc++.h"
using namespace std;

#define ll long long
#define ull unsigned long long
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define be begin()
#define en end()
#define all(x) (x).begin(),(x).end()
#define out cout<<setprecision(20)

typedef vector<int> vi;
typedef vector<ll> vll;
typedef set<int> si;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MOD = 1e9 + 7;
const int INF = 1e9;

vi primes;

void sieve_opt(int n)
{
    bool isPrime[n+5];

    for(int i=2;i<=n;i++)
        isPrime[i] = true;

    for(int i=4;i<=n;i+=2)
        isPrime[i] = false;

    for(int i=3;i<=n;i+=2)
        if(isPrime[i])
            for(int j=i*i;j<=n;j+=i*2)
                isPrime[j] = false;

    for(int i=2;i<=n;i++)
        if(isPrime[i])
            primes.pb(i);
}

void seg_sieve(ll l, ll r)
{
    bool isPrime[r-l+5];
    for(int i=0;i<=r-l+1;i++)
        isPrime[i] = true;
    isPrime[0] = l!=1;

    for(int i=0; primes[i]*primes[i]<=r; i++)
    {
        int cp=primes[i];
        ll base = ((l+cp-1)/cp)*cp;

        for(ll j=base; j<=r; j+=cp)
            isPrime[j-l] = false;

        isPrime[base-l] = cp == base;
    }
    for(int i=0; i<r-l+1; i++)
        if(isPrime[i])
            cout<<l+i<<endl;
}

int main(int argc, char* argv[])
{
    if(argc == 2 or argc == 3) freopen(argv[1], "r", stdin);
    if(argc == 3) freopen(argv[2], "w", stdout);
    ios::sync_with_stdio(false);

    sieve_opt(40000);
    int t;
    cin >> t;
    while(t--)
    {
        int l, r;
        cin >> l >> r;
        seg_sieve(l, r);
        cout<<endl;
    }    
    
    return 0;
}
