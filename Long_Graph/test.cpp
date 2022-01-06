#include <bits/stdc++.h>
using namespace std;

const int N = 2e3 + 5;
int s, t, vis[N], dist[N];
bool prime[N];

void sieve()
{

    memset(prime, true, sizeof prime);
    prime[0] = prime[1] = false;
    for (int i = 4; i < N; i += 2)
        prime[i] = false;
    for (int i = 3; i < N; i += 2)
        if (prime[i])
            for (int j = i * i; j < N; j += i * 2)
                prime[j] = false;
}

int rec(int parent)
{

    if (parent > t)
        return 1e3;
    if (parent == t)
        return 0;

    int &ret = dist[parent];
    if (~ret)
        return ret;
    ret = 1e3;

    vector<int> primeFactor;

    for (int i = 2; i * i <= parent; i++)
    {
        if (parent % i == 0 && prime[i])
        {
            primeFactor.push_back(i);
            primeFactor.push_back(parent / i);
        }
    }

    for (int i : primeFactor)
    {
        ret = min(ret, 1 + rec(parent + i));
    }

    return ret;
}

int main()
{

    sieve();

    int tc;
    cin >> tc;
    while (tc--)
    {
        cin >> s >> t;

        memset(dist, -1, sizeof dist);

        int Ans = rec(s);

        if (Ans >= 1000)
            cout << -1 << endl;
        else
            cout << Ans << endl;

        // cout << rec(s) << endl;
    }
}