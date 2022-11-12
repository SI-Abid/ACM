#include<bits/stdc++.h>
using namespace std;

signed main()
{
    #ifndef ONLINE_JUDGE
        freopen("in", "r", stdin);
        // freopen("output.txt", "w", stdout);
    #endif
    int n,m;
    cin>>n>>m;
    vector<vector<int>> graph(n+1);
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    vector<vector<int>> tree(n+1);
    vector<bool> visited(n+1,false);
    function<void(int)> dfs=[&](int v)
    {
        visited[v]=true;
        for(int u:graph[v])
        {
            if(!visited[u])
            {
                tree[v].push_back(u);
                dfs(u);
            }
        }
    };
    dfs(1);
    for(int i=1;i<=n;i++)
    {
        if(tree[i].size())
        {
            for(int j:tree[i])
                cout<<i<<" "<<j<<endl;
        }
    }
    return 0;
}