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
#define rb rbegin()
#define re rend()
#define all(x) (x).begin(),(x).end()
#define out cout<<setprecision(20)

typedef vector<int> vi;
typedef vector<ll> vll;
typedef set<int> si;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MOD = 1e9 + 7;
const int INF = 1e9;

bool bs(int)

void solve(int n)
{
    vi v(n);
    for (int i = 0; i < n; i++) cin>>v[i];
    
    int m; cin>>m;
    sort(all(v));
    
    for (int i = 0; i < n-1; i++)
        for (int j = i+1; j <= n-1; j++)
            if(v[i]+v[j]==m)
            {
                cout<<"Peter should buy books whose prices are "<<v[i]<<" and "<<v[j]<<endl<<endl;
                return;
            }
            
}

int main(int argc, char* argv[])
{
    if(argc == 2 or argc == 3) freopen(argv[1], "r", stdin);
    if(argc == 3) freopen(argv[2], "w", stdout);
    ios::sync_with_stdio(false);

    int n;
    while(cin>>n)
    {
        solve(n);
    }    
    
    return 0;
}
