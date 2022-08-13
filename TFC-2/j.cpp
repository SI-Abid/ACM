#include<bits/stdc++.h>
using namespace std;

#define ll long long
vector<pair<int,int>> adj[505];
ll dist[505];

// dijkstra
void dijkstra(int s)
{
    for(int i=0;i<505;i++)
    {
        dist[i]=INT_MAX;
    }
    dist[s]=0;
    priority_queue< pair<ll,int>, greater< pair<ll,int> > > pq;
    pq.push({0,s});
    while(!pq.empty())
    {
        int u=pq.top().second;
        ll d=pq.top().first;
        pq.pop();
        if(d>dist[u])
        {
            continue;
        }
        for(int i=0;i<adj[u].size();i++)
        {
            int v=adj[u][i].first;
            ll w=adj[u][i].second;
            if(dist[v]>dist[u]+w)
            {
                dist[v]=dist[u]+w;
                pq.push({dist[v],v});
            }
        }
    }
}

int main()
{
    int n,m,tc=1;
    while(cin>>n>>m)
    {
        for(int i=0;i<n;i++)
        {
            adj[i].clear();
        }
        for(int i=0;i<m;i++)
        {
            int u,v,w;
            cin>>u>>v>>w;
            if(min(u,v)==0 and max(u,v)==n-1)
            {
                // cout<<"NO\n";
                continue;
            }
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        dijkstra(0);
        cout<<"Set #"<<tc++<<"\n";
        cout<<dist[n-1]<<"\n";
    }
    return 0;
}