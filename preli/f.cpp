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

int main(int argc, char* argv[])
{
    if(argc == 2 or argc == 3) freopen(argv[1], "r", stdin);
    if(argc == 3) freopen(argv[2], "w", stdout);
    ios::sync_with_stdio(false);

    int t, it=1;
    cin>>t;
    while(t--)
    {
        ll a,b,m, d, k;
        cin>>a>>b>>m;
        d=abs(b-a);
        cout << "Case " << it++ << ": ";
        if(d==1)
        {
            cout<<m+1<<endl;
        }
        else if(d%2==0)
        {
            cout<<ceil((m+1)/2.0)<<endl;
        }
        else
        {
            k=(a+m)/d;
            cout<<m-k+1<<endl;
        }
    }
    return 0;
}
