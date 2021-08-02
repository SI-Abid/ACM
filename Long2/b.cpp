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

    ll t, tc=1;
    cin >> t;
    while(t--)
    {
        ll n, m, cnt=1;
        cin >> n;
        m=n;
        cout << "Case " << tc++ << ": ";
        ll cx=0;
        for (int i = 2; i < 8; i++)
        {
            while(n%i == 0)
            {
                n /= i;
                cx++;
            }
            cnt = max(cnt, cx);
        }
        cout << cnt << "\n";
    }
    return 0;
}
