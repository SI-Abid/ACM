#include <bits/stdc++.h>
using namespace std;

priority_queue<pair<long long int, int>> pq;
vector<pair<int, int>> x[100005];
long long int dis[100005];
int par[100005];
vector<int> path;

void pave(int n)
{
    if(n>0 && par[n] == -1)
        return;
    if (par[n] > 0)
        pave(par[n]);
    path.push_back(n);
}
void dijkstra(int src)
{
    for (int i = 1; i < 100005; i++)
    {
        par[i] = -1;
        dis[i] = 1e18;
    }
    dis[src] = 0;
    par[src] = 0;
    pq.push({-dis[src], src});
    while (!pq.empty())
    {
        int currentNode = pq.top().second;
        long long int currentCost = -pq.top().first;
        pq.pop();
        for (auto to : x[currentNode])
        {
            int node = to.first;
            long long int currentDis = currentCost + to.second;
            if (currentDis < dis[node])
            {
                dis[node] = currentDis;
                par[node] = currentNode;
                pq.push({-dis[node], node});
            }
        }
    }
}
int main()
{
    int node, edge;
    cin >> node >> edge;
    while (edge--)
    {
        int u, v, cost;
        cin >> u >> v >> cost;
        x[u].push_back({v, cost});
        x[v].push_back({u, cost});
    }
    dijkstra(1);
    pave(node);
    if(path.size())
        for (int i : path)
            cout << i << " ";
    else
        cout<<-1;
    cout << endl;
    return 0;
}