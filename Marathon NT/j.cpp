#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll extendedEuclid(ll a, ll b, ll &x, ll &y)
{
    if (b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }
    ll x1, y1;
    ll d = extendedEuclid(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

signed main()
{
    ll x, y;
    while (cin >> x >> y)
    {
        ll a, b;
        ll d = extendedEuclid(x, y, a, b);
        cout << a << " " << b << " " << d << endl;
    }
    return 0;
}