#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector x(n, vector<bool>(n)), y(n, vector<bool>(n));

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        x[a - 1][b - 1] = x[b - 1][a - 1] = true;
    }

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        y[a - 1][b - 1] = y[b - 1][a - 1] = true;
    }

    vector<int> p(n);
    for (int i = 0; i < n; i++)
    {
        p[i] = i;
    }

    do
    {
        bool ok = true;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (x[i][j] != y[p[i]][p[j]])
                {
                    ok = false;
                }
            }
        }
        if (ok)
        {
            puts("Yes");
            return 0;
        }
    } while (next_permutation(p.begin(), p.end()));

    puts("No");
    return 0;
}