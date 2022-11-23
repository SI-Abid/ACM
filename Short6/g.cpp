#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


// segmented sieve
vector<ll> sieve(ll a, ll b)
{
    vector<ll> primes;
    vector<bool> isPrime(b - a + 1, true);
    for (ll i = 2; i * i <= b; i++)
    {
        for (ll j = max(i * i, (a + i - 1) / i * i); j <= b; j += i)
        {
            isPrime[j - a] = false;
        }
    }
    for (ll i = a; i <= b; i++)
    {
        if (isPrime[i - a])
        {
            primes.push_back(i);
        }
    }
    return primes;
}

signed main()
{
    int _;
    cin >> _;
    for (int tc = 1; tc <= _; tc++)
    {
        // printf("Case %d: ",tc);

        ll a, b;
        cin >> a >> b;
        vector<ll> primes = sieve(a, b);
        for (ll x : primes)
            cout << x << endl;
        cout << endl;
    }
    return 0;
}