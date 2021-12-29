#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int failure[N], r[N], dp[N];

void build(string str, int n)
{
    int k = 0;

    for (int i = 2; i <= n; i++)
    {
        while (k && str[i] != str[k + 1])
            k = failure[k];

        if (str[i] == str[k + 1])
            k++;
        failure[i] = k;
    }
}

int main()
{
    string s;
    cin >> s;
    int n = s.size();

    build(" " + s, n);

    int c = 0;
    for (int i = failure[n]; i; i = failure[i])
    {
        r[c++] = i;
    }

    memset(dp, 0, sizeof(dp));

    for (int i = n; i; i--)
    {
        dp[failure[i]] += ++dp[i];
    }

    cout << c + 1 << endl;

    for (int i = c - 1; i >= 0; i--)
    {
        cout << r[i] << " " << dp[r[i]] << endl;
    }

    cout << n << " " << dp[n] << endl;

    return 0;
}