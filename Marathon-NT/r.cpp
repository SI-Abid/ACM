#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
// fibonacci number modulo m using fast doubling
pair<ll, ll> fib(ll n, ll m) {
    if (n == 0) return {0, 1};
    auto p = fib(n >> 1, m);
    ll c = (p.first * (2 * p.second - p.first + m)) % m;
    ll d = (p.first * p.first + p.second * p.second) % m;
    if (n & 1) return {d, (c + d) % m};
    else return {c, d};
}
signed main()
{
    ll _;
    cin >> _;
    for (ll tc = 1; tc <= _; tc++)
    {
        // prllf("Case %d: ",tc);

        ll n;
        cin >> n;
        auto ans = fib(n, 1000000007);
        cout << (ans.first + ans.second) % 1000000007 << endl;
    }
    return 0;
}