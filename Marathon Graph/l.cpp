#include<bits/stdc++.h>
using namespace std;
void dfs(int u, vector<bool> &vis, vector<vector<int>> &adj, vector<int> &col, int cur, int &ans){
    vis[u] = true;
    if(col[u] != cur){
        ans++;
        cur = col[u];
    }
    for(auto v: adj[u]){
        if(!vis[v]){
            dfs(v, vis, adj, col, cur, ans);
        }
    }
}

signed main()
{
    int n;
    cin>>n;
    vector<int> color(n+1);
    vector<vector<int>> adj(n+1);
    vector<bool> vis(n+1, false);
    for(int i=2;i<=n;i++)
    {
        int p;
        cin>>p;
        adj[p].push_back(i);
        // adj[i].push_back(p);
    }
    for(int i=1;i<=n;i++)
        cin>>color[i];
    int ans=1;
    int currernt_color=color[1];
    dfs(1, vis, adj, color, currernt_color, ans);
    cout<<ans<<endl;
    return 0;
}