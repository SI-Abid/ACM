#include <iostream>
#include <string>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <list>
#include <set>
#include <cmath>
#include <cstring>
 
#include <stdio.h>
#include <string.h>
#include <sstream>
#include <stdlib.h>
#include <vector>
#include <iomanip>
#include <ctime>
 
using namespace std;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
priority_queue<pair<long long int, pair<int, int> > > pq;
long long int dis[1005][1005];
long long int graph[1005][1005];

void dijkstra2d(int n, int m)
{
    for(int ii = 1; ii <= n; ii++)
    {
        for(int jj = 1; jj <= m; jj++)
        {
            dis[ii][jj] = 1e18;
        }
    }
    // dis[1][1] = 0;
    // pq.push({, {1, 1}});
    pq.push({-graph[1][1], {1, 1}});
    dis[1][1] = graph[1][1];
    
    while(pq.size())
    {
        pair<long long int, pair<int, int> > p = pq.top();
        pq.pop();
        int x = p.second.first;
        int y = p.second.second;
        long long int val = -p.first;
        
        for(int k = 0; k < 4; k++)
        {
            int a = x + dx[k];
            int b = y + dy[k];
            
            if(a < 1 || a > n || b < 1 || b > m)
                continue;
            
            // puts("{}");
            long long int cost = val + graph[a][b];
            // printf("%lld %d %d\n", cost, a, b);
            if(cost < dis[a][b])
            {
                // puts("[][]");
                dis[a][b] = cost;
                pq.push({-cost, {a, b}});
            }
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
        dijkstra2d(n, m);
        cout << dis[n][m] << endl;
        // for(int ii = 1; ii <= n; ii++)
        // {
        //     for(int jj = 1; jj <= m; jj++)
        //     {
        //         cout<<dis[ii][jj]<<" ";
        //     }
        //     cout<<endl;
        // }
        // for(int ii = 1; ii <= n; ii++)
        // {
        //     for(int jj = 1; jj <= m; jj++)
        //     {
        //         cout<<graph[ii][jj]<<" ";
        //     }
        //     cout<<endl;
        // }
    }

    return 0;
}