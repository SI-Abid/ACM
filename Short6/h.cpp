#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll bigMod(ll a, ll b, ll m)
{
    if (b == 0)
        return 1;
    ll x = bigMod(a, b / 2, m);
    x = (x * x) % m;
    if (b % 2)
        x = (x * a) % m;
    return x;
}

signed main()
{
    ll b, p, m;
    while (cin >> b >> p >> m)
    {
        cout << bigMod(b, p, m) << endl;
    }
    return 0;
}