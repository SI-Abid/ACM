#include<bits/stdc++.h>
using namespace std;

signed main()
{
    #ifndef ONLINE_JUDGE
        freopen("in", "r", stdin);
        // freopen("output.txt", "w", stdout);
    #endif
    int nodes,start;
    cin>>nodes>>start;
    vector<vector<int>> adj(nodes+1);
    for(size_t i=0;i<nodes;i++)
    {
        for (int j = 0; j < nodes; j++)
        {
            int x;
            cin>>x;
            if(x==1)
            {
                adj[i+1].push_back(j+1);
            }
        }
    }
    vector<bool> visited(nodes+1,false);
    vector<int> dist(nodes+1,-1);
    queue<int> q;
    q.push(start);
    visited[start]=true;
    dist[start]=0;
    while(!q.empty())
    {
        int v=q.front();
        q.pop();
        for(int u:adj[v])
        {
            if(!visited[u])
            {
                visited[u]=true;
                dist[u]=dist[v]+1;
                q.push(u);
            }
        }
    }
    for(int i=1;i<=nodes;i++)
    {
        cout<<dist[i]<<" ";
    }
    cout<<endl;
    return 0;
}