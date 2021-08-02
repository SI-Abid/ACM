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

    int k,l,m,n,d;
    cin >> k >> l >> m >> n >> d;
    if(min({k,l,m,n}) ==1)
    {
        cout<<d<<endl;
        return 0;
    }
    int ans = 0;
    for(int i=1;i<=d;i++)
    {
        if(i%k == 0 || i%l == 0 || i%m == 0 || i%n == 0)
            ans++;
    }
    cout<<ans<<endl;
    return 0;
}
