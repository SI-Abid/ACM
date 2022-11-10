#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
signed main()
{
    ll n, a, b;
    cin >> n >> a >> b;
    ll sum = n * (n + 1) / 2;
    for (ll i = 1; i <= n / a; i++)
    {
        sum -= i * a;
    }
    for (ll i = 1; i <= n / b; i++)
    {
        sum -= i * b;
    }
    ll gcd = (a * b) / __gcd(a, b);
    for (ll i = 1; i <= n / gcd; i++)
    {
        sum += i * gcd;
    }
    cout << sum << '\n';
    return 0;
}