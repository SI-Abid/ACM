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

const int MX = 1e5 + 5;
bool mark[MX];

void sieve()
{
    for(int i = 4; i < MX; i+=2)
        mark[i] = true;

    for(int i = 3; i*i < MX; i+=2)
        if(!mark[i])
            for(int j = i*i; j < MX; j+=i*2)
                mark[j] = true;
        
}

int main(int argc, char* argv[])
{
    if(argc == 2 or argc == 3) freopen(argv[1], "r", stdin);
    if(argc == 3) freopen(argv[2], "w", stdout);
    ios::sync_with_stdio(false);

    sieve();
    int n;
    cin>>n;
    if(n>2)
        cout<<2<<endl;
    else
        cout<<1<<endl;

    for(int i=2; i<n+2; i++)
    {
        cout<<mark[i]+1<<" ";
    }
    cout<<endl;
    
    return 0;
}
