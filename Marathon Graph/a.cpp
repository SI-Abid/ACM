#include<bits/stdc++.h>
using namespace std;

signed main()
{
    int _;
    cin>>_;
    for(int tc=1;tc<=_;tc++)
    {
        // printf("Case %d: ",tc);
    
        int nodes,edges;
        cin>>nodes>>edges;
        vector<vector<int>> adj(nodes+1);
        for(int i=0;i<edges;i++)
        {
            int u,v;
            cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<bool> vis(nodes+1,false);
        int start;
        cin>>start;
        queue<int> q;
        q.push(start);
        vis[start] = true;
        vector<int> dist(nodes+1,0);
        while(!q.empty())
        {
            int u = q.front();
            q.pop();
            for(int v : adj[u])
            {
                if(!vis[v])
                {
                    vis[v] = true;
                    dist[v] = dist[u]+1;
                    q.push(v);
                }
            }
        }
        for(int i=1;i<=nodes;i++)
        {
            if(i!=start)
            {
                if(dist[i]==0)
                    cout<<-1<<" ";
                else
                    cout<<dist[i]*6<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
}