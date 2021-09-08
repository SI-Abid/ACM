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

int main(int argc, char* argv[])
{
    if(argc == 2 or argc == 3) freopen(argv[1], "r", stdin);
    if(argc == 3) freopen(argv[2], "w", stdout);
    ios::sync_with_stdio(false);

    vi v;
    int n;    
    while (cin>>n)
    {
        v.pb(n);
        sort(all(v));
        if(v.size()&1)
        {
            cout<<v[v.size()/2]<<endl;
        }
        else
        {
            cout<<(v[v.size()/2-1]+v[v.size()/2])/2<<endl;
        }
    }
    
    return 0;
}
