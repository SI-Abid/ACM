#include<bits/stdc++.h>
using namespace std;

signed main()
{
    int _;
    cin>>_;
    for(int tc=1;tc<=_;tc++)
    {
        printf("Case %d: ",tc);
    
        int m;
        cin>>m;
        vector<pair<string,string>> v(m);
        map<string,int> node;
        int node_count=0;
        for(int i=0;i<m;i++)
        {
            cin>>v[i].first>>v[i].second;
            if(node.find(v[i].first)==node.end())
                node[v[i].first]=++node_count;
            if(node.find(v[i].second)==node.end())
                node[v[i].second]=++node_count;
        }
        vector<vector<int>> adj(node_count+1);
        for(int i=0;i<m;i++)
        {
            adj[node[v[i].first]].push_back(node[v[i].second]);
            // adj[node[v[i].second]].push_back(node[v[i].first]);
        }
        // check if graph has cycle
        vector<bool> vis(node_count+1,false);
        vector<bool> rec(node_count+1,false);
        bool cycle=false;
        function<void(int)> dfs=[&](int u){
            vis[u]=true;
            rec[u]=true;
            for(auto v:adj[u])
            {
                if(!vis[v])
                    dfs(v);
                else if(rec[v])
                    cycle=true;
            }
            rec[u]=false;
        };
        for(int i=1;i<=node_count;i++)
        {
            if(!vis[i])
                dfs(i);
        }
        if(cycle)
            cout<<"No"<<endl;
        else
            cout<<"Yes"<<endl;
            
    
    }
    return 0;
}