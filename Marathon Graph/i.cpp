#include<bits/stdc++.h>
using namespace std;

signed main()
{
    int n,m;
    cin>>n>>m;
    vector<int> val(n+1);
    for(int i=1;i<=n;i++)
        cin>>val[i];
    vector<vector<int>> adj(n+1);
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> vis(n+1);
    long long ans=0;
    int tmp;
    function<void(int)> dfs=[&](int u)
    {
        vis[u]=1;
        tmp=min(tmp,val[u]);
        for(int v:adj[u])
        {
            if(!vis[v])
                dfs(v);
        }
    };
    for(int i=1;i<=n;i++)
    {
        if(!vis[i])
        {
            tmp=INT_MAX;
            dfs(i);
            ans+=tmp;
        }
    }
    cout<<ans<<endl;
    return 0;
}
// #include<bits/stdc++.h>
// using namespace std;

// signed main()
// {
//     vector<tuple<int,int,int>> v;
//     v.push_back({1,2,3});
//     v.push_back({2,3,4});
//     for(auto [a,b,c]:v)
//         cout<<a<<" "<<b<<" "<<c<<endl;
//     return 0;
// }