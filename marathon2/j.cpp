#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> x[100005];
long long int dis[100005];

void dijkstra(int node)
{
    priority_queue<pair<long long int, int>> pq;
    for (int i = 0; i < 100005; i++)
        dis[i] = 1e18;
    dis[node] = 0;
    pq.push({-dis[node], node});
    while (pq.size())
    {
        int currentNode = pq.top().second;
        long long currentCost = -pq.top().first;
        pq.pop();
        for (auto to : x[currentNode])
        {
            long long currentDistance = currentCost + to.second;
            if (currentDistance < dis[to.first])
            {
                dis[to.first] = currentDistance;
                pq.push({-dis[to.first], to.first});
            }
        }
    }
}
void clear()
{
    for (int i = 0; i < 100005; i++)
        x[i].clear();
    memset(dis, 0, sizeof(dis));
}
int main()
{
    int t;
    cin >> t;
    for(int tc=1; tc<=t; tc++)
    {
        clear();
        int node, edge, s, t;
        cin >> node >> edge >> s >> t;
        while (edge--)
        {
            int u, v, cost;
            cin >> u >> v >> cost;
            x[u].push_back({v, cost});
            x[v].push_back({u, cost});
        }

        dijkstra(s);
        cout << "Case #" << tc << ": ";
        if (dis[t] == 1e18)
            cout << "unreachable" << endl;
        else
            cout << dis[t] << endl;
    }

    return 0;
}