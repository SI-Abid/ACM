#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void dfs(int u, vector<vector<pair<int,int>>> &g, vector<ll> &d, vector<bool> &vis) {
    vis[u] = true;
    for (auto v : g[u]) {
        if (!vis[v.first]) {
            d[v.first] = d[u] + v.second;
            dfs(v.first, g, d, vis);
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
        int n;
        cin>>n;
        vector<vector<pair<int,int>>> g(n+1);
        for(int i=1;i<n;i++)
        {
            int u,v,w;
            cin>>u>>v>>w;
            g[u].push_back({v,w});
            g[v].push_back({u,w});
        }
        vector<ll> d(n+1,0);
        vector<bool> vis(n+1,false);
        dfs(1,g,d,vis);
        int mx = max_element(d.begin(),d.end()) - d.begin();
        d.assign(n+1,0);
        vis.assign(n+1,false);
        dfs(mx,g,d,vis);
        ll ans = *max_element(d.begin(),d.end());
        cout<<ans<<endl;
    }
    return 0;
}