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

void solve()
{
    ll n;
    cin>>n;
    vll a(n), b(n);
    for(auto &x:a)
        cin>>x;
    
    for(auto &x:b)
    {
        cin>>x;
    }
    ll mn=INF, mx=0;
    for(int i=0; i<n; i++)
    {
        mn=INF;
        for(int j=0; j<n; j++)
        {
            mn=min(abs(a[i]-b[j]), mn);

        }
        mx=max(mx, mn);
    }
    out<<mx<<endl;
}

int main(int argc, char* argv[])
{
    if(argc == 2 or argc == 3) freopen(argv[1], "r", stdin);
    if(argc == 3) freopen(argv[2], "w", stdout);
    ios::sync_with_stdio(false);

    solve();
    
    return 0;
}
