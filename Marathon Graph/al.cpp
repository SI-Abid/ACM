#include<bits/stdc++.h>
using namespace std;

signed main()
{
    int _;
    cin>>_;
    for(int tc=1;tc<=_;tc++)
    {
        printf("Case %d:\n",tc);
    
        int nodes;
        cin>>nodes;
        vector<vector<pair<int,int>>> adj(nodes+1);
        for(size_t i=0;i<nodes-1;i++)
        {
            int u,v,w;
            cin>>u>>v>>w;
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        vector<int> dist1(nodes+1,0);
        vector<int> dist2(nodes+1,0);
        vector<bool> vis(nodes+1,false);
        function<void(int)> dfs=[&](int node)
        {
            vis[node]=true;
            for(auto child:adj[node])
            {
                if(!vis[child.first])
                {
                    dist1[child.first]=dist1[node]+child.second;
                    dfs(child.first);
                }
            }
        };
        dfs(0);
        int leaf1=max_element(dist1.begin(),dist1.end())-dist1.begin();
        fill(vis.begin(),vis.end(),false);
        fill(dist1.begin(),dist1.end(),0);
        dfs(leaf1);
        int leaf2=max_element(dist1.begin(),dist1.end())-dist1.begin();
        fill(vis.begin(),vis.end(),false);
        dist2=dist1;
        fill(dist1.begin(),dist1.end(),0);
        dfs(leaf2);
        for(int i=0;i<nodes;i++)
        {
            printf("%d\n",max(dist1[i],dist2[i]));
        }

    }
    return 0;
}