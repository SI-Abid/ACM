#include <bits/stdc++.h>
using namespace std;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

long long int graph[1005][1005];

void grid(int n, int m, int i, int j)
{
    for(int i = 1; i <= n; i++)
    {   
        for(int j = 1; j <= m; j++)
        {
            vector<long long int> dis;
            for (int k = 0; k < 4; k++)
            {
                int x = i + dx[k];
                int y = j + dy[k];
                if (x >= 1 && x <= n && y >= 1 && y <= m)
                {
                    dis.push_back(graph[i][j] + graph[x][y]);
                }
            }
            graph[i][j] = *min_element(dis.begin(), dis.end());
        }
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n,m;
        cin>>n>>m;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                cin>>graph[i][j];
            }
        }
        grid(n, m, 1, 1);
        cout << graph[n][m] << endl;
    }

    return 0;
}