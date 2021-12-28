#include <bits/stdc++.h>
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
#define all(x) (x).begin(), (x).end()
#define out cout << setprecision(20)

typedef vector<int> vi;
typedef vector<ll> vll;
typedef set<int> si;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MOD = 1e9 + 7;
const int INF = 1e9;

ll hash_2d[1001][1001];
ll hash_pat[101];
ll p = 31;
ll mod = 1e9 + 7;
ll inverse_p[1001];

int binPow(ll x, ll n)
{
    if (n == 0)
        return 1;
    ll res = binPow(x, n / 2);
    if (n & 1)
        return (res * res * x) % mod;
    else
        return (res * res) % mod;
}

ll sub_hash(ll hashi, ll hashj, ll pi)
{
    ll ans = (hashj - hashi) % mod;
    ll temp = binPow(pi, mod - 2);
    return (ans * temp) % mod;
}

void solve()
{
    // ll pp;
    int n, m, x, y;

    cin >> n >> m;
    vector<string> s(n);
    for (int i = 0; i < n; i++)
        cin >> s[i];

    cin >> x >> y;
    vector<string> pat(x);
    for (int i = 0; i < x; i++)
        cin >> pat[i];


    ll ans = 0;
    vll pp(n);
    pp[0] = 1;
    for (int i = 1; i < n; i++)
    {
        pp[i] = (pp[i - 1] * p) % mod;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            hash_2d[i + 1][j + 1] = (hash_2d[i + 1][j] + (s[i][j] - 96) * pp[j]) % mod;
        }
    }

    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            hash_pat[i + 1] += ((pat[i][j] - 96) * pp[j]) % mod;
        }
    }

    for (int i = 0; i < n - x; i++)
    {
        for (int j = 0; j < m - y; j++)
        {
            bool match = true;
            int k = i;
            while (match)
            {
                ll suha = sub_hash(hash_2d[k][j], hash_2d[k][j + y], pp[j]);
                printf("%lld  %lld\n", suha, hash_pat[k]);

                if (suha != hash_pat[k])
                {
                    match = false;
                    // cout << "NO"<<endl;
                    break;
                }
                k++;
            }
            if (match)
                ans++;
        }
    }
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            cout << hash_2d[i][j] << " ";
        }
        cout << endl;
    }

    for (int j = 0; j <= x; j++)
    {
        cout << hash_pat[j] << endl;
    }

    cout << "*****" << ans << endl;
}

int main(int argc, char *argv[])
{
    if (argc == 2 or argc == 3)
        freopen(argv[1], "r", stdin);
    if (argc == 3)
        freopen(argv[2], "w", stdout);
    ios::sync_with_stdio(false);

    freopen("in", "r", stdin);

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}