#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int mx = 1e6 + 5;
const ll mod = 1e9 + 7;
bool prime[mx];
vector<ll> v;

void seive()
{
    prime[0] = prime[1] = true;

    for (int i = 2; i * i < mx; i++)
    {
        for (int j = i * i; j < mx; j += i)
        {
            prime[j] = true;
        }
    }

    for (int i = 2; i < mx; i++)
    {
        if (!prime[i])
            v.push_back(i);
    }
}
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    seive();

    int n, x;
    cin >> n;
    map<int, ll> m;
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> x;

        for (int j = 0; j < v.size() && v[j] * v[j] <= x; j++)
        {
            if (x % v[j] == 0)
            {
                cnt = 0;
                while (x % v[j] == 0)
                {
                    cnt++;
                    x /= v[j];
                }
                m[v[j]] += cnt;
            }
        }

        if (x > 1)
        {
            m[x]++;
        }
    }

    ll ans = 1;
    for (auto w : m)
    {
        // cout << w.first << " " << w.second << "\n";
        ans = ((ans % mod) * ((w.second + 1) % mod)) % mod;
    }

    cout << ans << "\n";

    return 0;
}