#include<bits/stdc++.h>
using namespace std;

#define ll long long
vector< pair< int, ll > > adj[50005];  
bool visited[50005];
vector<vector<int> > dist;
vector<int> parent;

void bfs(int s)
{
    queue<int> q;
    q.push(s);
    visited[s] = true;
    parent[s] = 0;
    for (size_t i = 0; i < 50005; i++)
    {
        dist[i][i] = 0;
    }
    
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        for (size_t i = 0; i < adj[u].size(); i++)
        {
            int v = adj[u][i].first;
            ll w = adj[u][i].second;
            if(!visited[v])
            {
                q.push(v);
                visited[v] = true;
                parent[v] = u;
                dist[u][v] = dist[v][u] = dist[]
            }
        }
    }
}

int main()
{
    dist.resize(50005, vector<int>(50005));
    int n;
    cin>>n;
    for(int i = 0; i < n-1; i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back(make_pair(v,w));
        adj[v].push_back(make_pair(u,w));
    }
    bfs(0);
    int q;
    cin>>q;
    while(q--)
    {
        int u,v;
        cin>>u>>v;
        cout<< dist[u][v] <<"\n";
    }
    return 0;
}