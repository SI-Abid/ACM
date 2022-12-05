#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll binPow(ll a, ll b, ll m)
{
    ll res = 1;
    while (b > 0)
    {
        if (b & 1)
        {
            res = (res * a) % m;
        }
        a = (a * a) % m;
        b >>= 1;
    }
    return res;
}

signed main()
{
    ll x, y, n;
    while(cin >> x >> y >> n)
    {
        // cin >> x >> y >> n;
        cout << binPow(x, y, n) << endl;
    }
    return 0;
}