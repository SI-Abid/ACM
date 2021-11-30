// AUTHOR: Md Jahirul Islam Hridoy
#include <bits/stdc++.h>
using namespace std;

#define SC              scanf
#define PF              printf
#define ull             unsigned long long
#define ld              long double
#define F               first
#define S               second
#define pb              push_back
#define sort_a(a)       sort(a.begin(), a.end());
#define sort_d(a)       sort(a.rbegin(), a.rend());
#define READ(f)         freopen(f, "r", stdin)
#define WRITE(f)        freopen(f, "w", stdout)
#define rev(s)          reverse(s.begin(), s.end())
#define P(ok)           cout << (ok ? "YES\n" : "NO\n")
#define __Heart__       ios_base ::sync_with_stdio(false); cin.tie(NULL);
#define ll              long long
typedef pair<ll, ll>    PII;

void solve()
{
    ll n, k;
    cin >> n >> k;
    ll a[n];
    map<int, int> bit;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        for (int j = 0; j < 50; j++)
        {
            if ((1LL << j) & a[i])
                bit[j]++;
        }
    }
    ll x = 0, Ans = 0;
    for (ll i = 50; i >= 0; i--)
    {
        ll zero = n - bit[i];
        ll add = x + (1LL << i);
        if (zero >= bit[i] && add <= k)
            x = add;
    }
    for (int i = 0; i < n; i++)
        Ans += (a[i] ^ x);

    cout << Ans << "\n";
}
int main()
{
    __Heart__ 
    int t;
    t = 1;
    while (t--)
        solve();
}
