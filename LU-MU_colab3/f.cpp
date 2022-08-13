#include <bits/stdc++.h>
using namespace std;

void solve();

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    // {
    //     clock_t tStart = clock();

        solve();

    //     clock_t tEnd = clock();
    //     double time = (tEnd - tStart) / (double)CLOCKS_PER_SEC;
    //     printf("Time taken: %.10lf seconds\n", time);
    // }
    // for(auto i:ans)
    // {
    //     for(auto j:i)
    //     {
    //         cout<<j<<" ";
    //     }
    //     cout<<endl;
    // }

    return 0;
}

void solve()
{

    int n;
    cin >> n;
    vector<string> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    vector<vector<int>> ans(n, vector<int>(n, 0));
    vector<vector<int>> Vmax(n, vector<int>(n, 0));
    vector<vector<int>> Hmax(n, vector<int>(n, 0));
    vector<vector<int>> Dmax(n, vector<int>(n, 0));
    vector<vector<int>> Umax(n, vector<int>(n, 0));
    long long counter = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (a[i][j] == '.')
            {
                cout << "0 ";
                counter++;
                continue;
            }
            int cnth, cntv, cntd1, cntd2;
            cnth = cntv = cntd1 = cntd2 = 0;
            int x, y;

            if (j > 0 && ans[i][j - 1] != 0) // if previous cell contains answer
            {
                cnth = Hmax[i][j] = Hmax[i][j - 1];
            }
            else    // otherwise calculate for the count
            {
                y = j;
                while (y < n && a[i][y] == 'X')
                {
                    cnth++;
                    y++;
                    counter++;
                }
                y = j - 1;
                while (y >= 0 && a[i][y] == 'X')
                {
                    cnth++;
                    y--;
                    counter++;
                }
                Hmax[i][j] = cnth;
            }
            if (i > 0 && ans[i - 1][j] != 0)
            {
                cntv = Vmax[i][j] = Vmax[i - 1][j];
            }
            else
            {
                x = i;
                while (x < n && a[x][j] == 'X')
                {
                    cntv++;
                    x++;
                    counter++;
                }
                x = i - 1;
                while (x >= 0 && a[x][j] == 'X')
                {
                    cntv++;
                    x--;
                    counter++;
                }
                Vmax[i][j] = cntv;
            }
            if (i > 0 && j > 0 && ans[i - 1][j - 1] != 0)
            {
                cntd1 = Dmax[i][j] = Dmax[i - 1][j - 1];
            }
            else
            {
                x = i;
                y = j;
                while (x < n && y < n && a[x][y] == 'X')
                {
                    cntd1++;
                    x++;
                    y++;
                    counter++;
                }
                x = i - 1;
                y = j - 1;
                while (x >= 0 && y >= 0 && a[x][y] == 'X')
                {
                    cntd1++;
                    x--;
                    y--;
                    counter++;
                }
                Dmax[i][j] = cntd1;
            }
            if(j<n-1 && ans[i][j+1]!=0)
            {
                cntd2 = Umax[i][j] = Umax[i][j+1];
            }
            else
            {
                x = i;
                y = j;
                while (x >= 0 && y < n && a[x][y] == 'X')
                {
                    cntd2++;
                    x--;
                    y++;
                    counter++;
                }
                x = i + 1;
                y = j - 1;
                while (x < n && y >= 0 && a[x][y] == 'X')
                {
                    cntd2++;
                    x++;
                    y--;
                    counter++;
                }
                Umax[i][j] = cntd2;
            }
            ans[i][j] = max(max(cnth, cntv), max(cntd1, cntd2));
            cout << ans[i][j] << " ";
        }

        cout << "\n";
    }
    // cout<<counter<<"\n";
}