#include<bits/stdc++.h>
using namespace std;

signed main()
{
    int _;
    cin>>_;
    for(int tc=1;tc<=_;tc++)
    {
        printf("Case %d:\n",tc);
    
        int n,m;
        cin>>n>>m;
        vector<vector<pair<int,int>>> adj(n);
        for (int i = 0; i < m; i++)
        {
            int u,v,w;
            cin>>u>>v>>w;
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        int start;
        cin>>start;
        vector<int> dist(n,INT_MAX);
        dist[start]=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,start});
        while(!pq.empty())
        {
            int u=pq.top().second;
            int d=pq.top().first;
            pq.pop();
            if(d>dist[u])
                continue;
            for(auto v:adj[u])
            {
                if(max(dist[u],v.second)<dist[v.first])
                {
                    dist[v.first]=max(dist[u],v.second);
                    pq.push({dist[v.first],v.first});
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            if(dist[i]==INT_MAX)
                cout<<"Impossible"<<endl;
            else
                cout<<dist[i]<<endl;
        }
    }
    return 0;
}