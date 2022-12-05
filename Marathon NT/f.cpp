#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll bigMod(ll a, ll b, ll m)
{
    if (b == 0)
        return 1;
    ll x = bigMod(a, b / 2, m);
    x = (x * x) % m;
    if (b % 2 == 1)
        x = (x * a) % m;
    return x;
}

signed main()
{
    int _;
    cin >> _;
    for (int tc = 1; tc <= _; tc++)
    {

        ll n;
        cin >> n;
        ll ans = 1;
        if(n<4)
        {
            cout<<n<<endl;
            continue;
        }
        if (n % 3 == 1)
        {
            ans = bigMod(3, n / 3 - 1, 1000000007);
            ans *= 4;
            ans %= 1000000007;
        }
        else if (n % 3 == 2)
        {
            ans = bigMod(3, n / 3, 1000000007);
            ans *= 2;
            ans %= 1000000007;
        }
        else
        {
            ans = bigMod(3, n / 3, 1000000007);
        }
        cout << ans << endl;
    }
    return 0;
}