#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    for (int tc = 1; tc <= t; tc++)
    {
        int r, c;
        cin >> r >> c;
        cout << "Case #" << tc << ":\n";
        for (int i = 0; i < r + r + 1; i++)
        {
            for (int j = 0; j < c + c + 1; j++)
            {
                if (i < 2 and j < 2)
                {
                    cout << ".";
                    continue;
                }
                if (i % 2 == 0)
                {
                    if (j % 2 == 0)
                    {
                        cout << "+";
                    }
                    else
                    {
                        cout << "-";
                    }
                }
                else
                {
                    if (j % 2 == 0)
                    {
                        cout << "|";
                    }
                    else
                    {
                        cout << ".";
                    }
                }
            }
            cout << "\n";
        }
    }
    return 0;
}