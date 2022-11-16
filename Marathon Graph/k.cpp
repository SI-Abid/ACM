#include<bits/stdc++.h>
using namespace std;

void dfs(int u,vector<vector<int>> &adj,vector<bool> &vis)
{
    vis[u]=true;
    for(int v:adj[u])
        if(!vis[v])
            dfs(v,adj,vis);
}

signed main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>> adj(n+1);
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<bool> vis(n+1);
    dfs(1,adj,vis);
    bool allVisited=true;
    for(int i=1;i<=n;i++)
    {
        allVisited&=vis[i];
    }
    if(n==m and allVisited)
    {
        cout<<"FHTAGN!"<<endl;
        return 0;
    }
    cout<<"NO"<<endl;
    return 0;
}