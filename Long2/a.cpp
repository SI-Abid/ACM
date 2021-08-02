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
#define all(x) (x).begin(), (x).end()
#define out cout << setprecision(20)

typedef vector<int> vi;
typedef vector<ll> vll;
typedef set<int> si;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MOD = 1e9 + 7;
const int INF = 1e9;

void printAll(int l, int n)
{
    vi v;
    for(int i=1; i*i<=n; i++)
    {
        if(n%i == 0)
        {
            v.pb(i);
            if(i*i != n)
                v.pb(n/i);
        }
    }
    sort(all(v));
    for(auto x: v)
        if(x>l)
            cout << " " << x;
    
    cout << endl;
}
int main(int argc, char *argv[])
{
    if (argc == 2 or argc == 3)
        freopen(argv[1], "r", stdin);
    if (argc == 3)
        freopen(argv[2], "w", stdout);
    ios::sync_with_stdio(false);

    int t, tc = 1;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        cout << "Case " << tc++ << ":";
        if (k*2>=n)
        {
            cout << " impossible\n";
        }
        else
        {
            int ate = n - k;
            printAll(k, ate);
        }
    }

    return 0;
}
