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

void printAll(int i, int n)
{
    // vi divs(n + 1, 0);
    for (int j = i; j * j <= n; j++)
    {
        if (n % j == 0)
        {
            cout << j << " ";
            if (n / j != j)
            {
                cout << n / j << " ";
            }
        }
    }
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
        int rem = n - k;
        cout << "Case " << tc++ << ": ";
        if (k > rem)
        {
            cout << "impossible\n";
        }
        else if (k == 0)
        {
            printAll(1, rem);
        }
        else
        {
            printAll(2, rem);
        }
    }

    return 0;
}
