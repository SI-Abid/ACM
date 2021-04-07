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

int main()
{
    // if (argc == 2 or argc == 3)
    //     freopen(argv[1], "r", stdin);
    // if (argc == 3)
    //     freopen(argv[2], "w", stdout);
    ios::sync_with_stdio(false);
    // cin.tie(0);
    // cout.tie(0);

    int t, it = 1;
    cin >> t;
    while (t--)
    {
        ll n, cluster = 0, lsum = 0, mx=-10000000;
        cin >> n;
        ll ar[n];
        for (ll i = 0; i < n; i++)
        {
            cin >> ar[i];
            mx=max(mx, ar[i]);
            if (ar[i] > 0)
            {
                lsum += ar[i];
            }
        }
        if(lsum==0)
        {
            cout << "Case " << it++ << ": " << mx << " " << cluster << endl;
            continue;
        }
        ll di = 0, dj = n - 1;
        while (di < n && ar[di] <= 0)
        {
            di++;
        }
        while (dj >= 0 && ar[dj] <= 0)
        {
            dj--;
        }
        for (ll i = di; i < dj; i++)
        {
            if (ar[i] < 0)
            {
                cluster++;
                while (i<dj && ar[i] <= 0)
                {
                    i++;
                }
            }
        }
        // printf("Case %d: %lld %lld\n", it++, lsum, cluster);
        cout << "Case " << it++ << ": " << lsum << " " << cluster << endl;
    }
    return 0;
}
