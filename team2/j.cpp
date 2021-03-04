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
    int m,n,rx,ry,x,y;
    x=y=0;
    cin>>m>>n>>rx>>ry;
    string s;
    int sz;
    cin>>sz>>s;
    for(auto c:s)
    {
        switch (c)
        {
        case 'L':   x--; break;
        case 'R':   x++; break;
        case 'U':   y++; break;
        case 'D':   y--; break;
        default:
            break;
        }
    }
    if(x==rx and y==ry)
    {
        cout<<"REACHED\n";
    }
    else if(x<0||y<0||x>m||y>n)
    {
        cout<<"DANGER\n";
    }
    else
    {
        cout<<"SOMEWHERE\n";
    }

}

int main(int argc, char* argv[])
{
    if(argc == 2 or argc == 3) freopen(argv[1], "r", stdin);
    if(argc == 3) freopen(argv[2], "w", stdout);
    ios::sync_with_stdio(false);

    int t, i=1;
    for(cin>>t;t;t--)
    {
        cout<<"Case "<<i++<<": ";
        solve();
    }    
        
    
    return 0;
}
