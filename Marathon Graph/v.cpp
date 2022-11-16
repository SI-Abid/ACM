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
        vector<vector<int>> adj(n+1);
        for (int i = 0; i < m; i++)
        {
            int u,v;
            cin>>u>>v;
            adj[u].push_back(v);
        }
        // get in degree of each node
        vector<int> in(n+1);
        for (int i = 1; i <= n; i++)
        {
            for(auto x:adj[i])
            {
                in[x]++;
            }
        }
        function<void(int)> dfs=[&](int u)
        {
            for(auto x:adj[u])
            {
                in[x]--;
                if(in[x]==0)
                {
                    dfs(x);
                }
            }
        };
        int ans=0;
        for (int i = 1; i <= n; i++)
        {
            if(in[i]==0)
            {
                ans++;
                dfs(i);
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}