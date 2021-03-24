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
    char ca[3][3];
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            cin>>ca[i][j];

    bool ok=false;
    for(int i=0; i<2; i++)
        for(int j=0; j<2; j++)
        {
            if(ca[i][j]=='l' && ca[i+1][j]=='l' && ca[i+1][j+1]=='l')
            {
                ok=true;
                break;
            }
        }

    puts(ok?"yes":"no");
}

int main(int argc, char* argv[])
{
    if(argc == 2 or argc == 3) freopen(argv[1], "r", stdin);
    if(argc == 3) freopen(argv[2], "w", stdout);
    ios::sync_with_stdio(false);

    int t;
    for(cin>>t;t;t--)
        solve();

    return 0;
}
