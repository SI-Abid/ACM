/*
    nCr % m     ;   1 <= r < n <= 10^7, 1 <= m <= 10^9+7
    T <= 10^6
*/
#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define ll long long
vector<ll> fact;

ll binpow(ll a, ll b)
{
    ll res = 1;
    while (b)
    {
        if (b & 1)
            res = (res * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return res;
}

int main()
{
    fact.resize(10000001);
    fact[0] = 1;
    for (ll i = 1; i <= 10000000; i++)
    {
        fact[i] = (fact[i - 1] * i) % MOD;
    }
    int t;
    cin >> t;
    while (t--)
    {
        ll n, r;
        cin >> n >> r;
        ll ans = 0;
        ans = (fact[n] * binpow(fact[r], MOD - 2)) % MOD;
        ans = (ans * binpow(fact[n - r], MOD - 2)) % MOD;
        cout << ans << endl;
    }
    return 0;
}