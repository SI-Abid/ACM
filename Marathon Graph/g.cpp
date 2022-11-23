#include<bits/stdc++.h>
using namespace std;

signed main()
{
    int n,m;
    cin>>n>>m;
    int a,b;
    cin>>a>>b;
    vector<vector<int>> adj(n+1);
    for(int i=0;i<m;i++)
    {
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    vector<bool> vis(n+1,false);
    vector<int> dist(n+1,0);
    queue<int> q;
    q.push(a);
    vis[a]=true;
    while(!q.empty())
    {
        int w=q.front();
        q.pop();
        for(auto x:adj[w])
        {
            if(!vis[x])
            {
                vis[x]=true;
                dist[x]=dist[w]+1;
                q.push(x);
            }
        }
    }
    if(dist[b]==0)
    {
        cout<<"-1";
    }
    if(dist[b])
    {
        cout<<dist[b]<<'\n';
        vector<int> path;
        int x=b;
        while(x!=a)
        {
            path.push_back(x);
            for(auto y:adj[x])
            {
                if(dist[y]==dist[x]-1)
                {
                    x=y;
                    break;
                }
            }
        }
        path.push_back(a);
        reverse(path.begin(),path.end());
        for(auto x:path)
        {
            cout<<x<<" ";
        }
    }
    return 0;
}