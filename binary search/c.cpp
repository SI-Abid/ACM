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

    int n;
    cin>>n;
    vi v(n);
    for(int i=0; i<n; i++)  cin>>v[i];
    int m;
    cin>>m;
    vi w(m);
    for(int i=0; i<m; i++)  cin>>w[i];
    
    for (int k:w)
    {
        auto lo = lower_bound(all(v),k)-v.begin();
        auto up = upper_bound(all(v),k)-v.begin();
        // cout<<v[lo-1]?v[lo-1]:"X"<<" "<<v[up]?v[up]:"X"<<endl;
        if(v[lo-1])
        {
            cout<<v[lo-1];
        }
        else
        {
            cout<<"X";
        }
        cout<<" ";
        if(v[up])
        {
            cout<<v[up];
        }
        else
        {
            cout<<"X";
        }
        cout<<endl;
    }
    
    return 0;
}
