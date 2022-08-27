#include <bits/stdc++.h>
using namespace std;

template <typename T, typename U>
ostream &operator<<(ostream &os, const map<T, U> &m)
{
    for (auto [k, v] : m)
    {
        os << k << ' ' << v << '\n';
    }
    return os;
}
vector<long long> prime;
vector<bool> isPrime(SIZE + 1, true);
void init(int SIZE = 1e8)
{
    isPrime[0] = isPrime[1] = false;
    for (int i = 4; i <= SIZE; i += 2)
    {
        isPrime[i] = false;
    }
    for (int i = 3; i * i <= SIZE; i += 2)
    {
        if (isPrime[i])
        {
            for (int j = i * i; j <= SIZE; j += i)
            {
                isPrime[j] = false;
            }
        }
    }
    for (int i = 2; i <= SIZE; i++)
    {
        if (isPrime[i])
            prime.push_back(i);
    }
}

// prime factorization of n = a^x + b^y + ...
int factor(long long n)
{
    int ans = INT_MAX;
    int cnt;
    for (auto p : prime)
    {
        if (p * p > n)
            break;
        if (n % p == 0)
        {
            cnt = 0;
            while (n % p == 0)
            {
                n /= p;
                cnt++;
            }
            ans = min(ans, cnt);
        }
    }
    if (n != 1)
    {
        ans = min(ans, 1);
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    long long n;
    cin >> t;
    init();
    for (int tc = 1; tc <= t; tc++)
    {
        printf("Case %d: ", tc);

        cin >> n;
        // cout<< n << '\n';
        if(n<0)
        {
            int pow = factor(-n);
            if(pow&1)
                cout<<pow<<'\n';
            else
            {
                while (pow%2==0)
                {
                    pow>>=1;
                }
                cout<<pow<<'\n';
            }
        }
        else
            cout << factor(n) << '\n';
    }
    return 0;
}