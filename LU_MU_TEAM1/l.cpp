#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define MOD 1000000007
typedef unsigned long long int ull;
#define fastIO               \
    ios::sync_with_stdio(0); \
    cin.tie(0), cout.tie(0);

vector<pair<int, int>> v;
// vector<ll>primes;
vector<bool> isPrime;

void sieve(int n)
{
    n = n + 5;
    isPrime.resize(n + 1, true);
    isPrime[0] = isPrime[1] = false;

    for (int i = 4; i <= n; i += 2)
        isPrime[i] = false;

    for (int i = 3; i * i <= n; i += 2)
        if (isPrime[i])
            for (int j = i * i; j <= n; j += 2 * i)
                isPrime[j] = false;

}
    // for(int p=2;p<=n;p++)
    // {
    //     if(isPrime[p])
    //     {
    //         primes.push_back(p);
    //     }
    // }
// }

void count(int n)
{
    int cnt1 = 0, cnt2 = 0;
    for (int i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            cnt1++;
            if (i != n / i)
                cnt1++;
            if (isPrime[i])
                cnt2++;
            if (isPrime[n / i])
                cnt2++;
        }
    }
    v.push_back({cnt1, cnt2});
}

int main()
{
    // fastIO 
    sieve(2000000);
    for (int i = 2; i <= 2000000; i++)
    {
        count(i);
    }
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n;
        scanf("%d", &n);
        printf("%d\n", v[n - 2].first- v[n - 2].second);
    }
}