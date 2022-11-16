#include<bits/stdc++.h>
using namespace std;

signed main()
{
    int _;
    cin>>_;
    for(int tc=1;tc<=_;tc++)
    {
        printf("Case %d: ",tc);
    
        int n,m;
        cin>>n>>m;
        vector<vector<pair<int,int>>> adj(n+1);
        for (int i = 0; i < m; i++)
        {
            int u,v,w;
            cin>>u>>v>>w;
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        vector<int> dist(n+1,INT_MAX);
        dist[1]=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,1});
        while(!pq.empty())
        {
            int u=pq.top().second;
            int d=pq.top().first;
            pq.pop();
            if(d>dist[u])
                continue;
            for(auto v:adj[u])
            {
                if(dist[u]+v.second<dist[v.first])
                {
                    dist[v.first]=dist[u]+v.second;
                    pq.push({dist[v.first],v.first});
                }
            }
        }
        if(dist[n]==INT_MAX)
            cout<<"Impossible"<<endl;
        else
            cout<<dist[n]<<endl;
    
    }
    return 0;
}