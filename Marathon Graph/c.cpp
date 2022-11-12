#include<bits/stdc++.h>
using namespace std;

void dfs(int v, vector<vector<int>> &g, vector<bool> &used, int &cnt) {
    used[v] = true;
    cnt++;
    for (int u : g[v]) {
        if (!used[u]) {
            dfs(u, g, used, cnt);
        }
    }
}

signed main()
{
    #ifndef ONLINE_JUDGE
        freopen("in", "r", stdin);
        // freopen("output.txt", "w", stdout);
    #endif
    int nodes, edges;
    cin >> nodes >> edges;
    vector<vector<int>> adj(nodes+1);
    for(int i=0;i<edges;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int used=0;
    vector<bool> visited(nodes+1,false);
    dfs(1,adj,visited,used);
    if(used==nodes)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
    return 0;
}