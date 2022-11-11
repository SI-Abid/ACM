#include<bits/stdc++.h>
using namespace std;

#define RED 1
#define BLUE 0

void dfs(int u, vector<vector<int>> &adj, vector<bool> &vis, int color, int &cnt, int &compCnt)
{
    vis[u] = true;
    cnt+=color;
    compCnt++;
    for (int v : adj[u])
    {
        if (!vis[v])
        {
            if (color == RED)
                dfs(v, adj, vis, BLUE, cnt, compCnt);
            else
                dfs(v, adj, vis, RED, cnt, compCnt);
        }
    }
}

signed main()
{
    int _;
    cin>>_;
    for(int tc=1;tc<=_;tc++)
    {
        printf("Case %d: ",tc);
    
        int edges;
        cin>>edges;

        vector<vector<int>> adj(20002);
        set<int> nodes;
        for(int i=0;i<edges;i++)
        {
            int u,v;
            cin>>u>>v;
            nodes.insert(u);
            nodes.insert(v);
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<bool> vis(20002,false);
        int ans = 0;
        for(int i : nodes)
        {
            if(!vis[i])
            {
                int cnt = 0, compCnt = 0;
                dfs(i,adj,vis,RED,cnt,compCnt);
                ans += max(cnt,compCnt-cnt);
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}