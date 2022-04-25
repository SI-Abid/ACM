#include<bits/stdc++.h>
using namespace std;

#define ll long long
vector<int> adj[1001];
bool vis[1001];
vector<int> ans;

void dfs(int u)
{
    vis[u]=true;
    for(int i=0;i<adj[u].size();i++)
    {
        int v=adj[u][i];
        if(!vis[v])
        {
            dfs(v);
        }
    }
    ans.push_back(u);
}

void clear()
{
    for(int i=1;i<=1000;i++)
    {
        adj[i].clear();
        vis[i]=false;
    }
}

int main()
{
    int n,m;
    while (cin>>n>>m)
    {
        if(n+m==0)
            break;
        clear();
        ans.clear();
        for (int i = 0; i < m; i++)
        {
            int u,v;
            cin>>u>>v;
            adj[u].push_back(v);
        }        
        for(int i=1;i<=n;i++)
        {
            if(!vis[i])
            {
                dfs(i);
            }
        }
        for(int i=ans.size()-1;i>=0;i--)
        {
            cout<<ans[i]<<" ";
        }
        cout<<"\n";
    }

    return 0;
}