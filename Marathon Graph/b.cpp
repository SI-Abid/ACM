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
    int n,s;
    cin>>n>>s;
    vector<vector<int>> adj(n+1);
    for(int i=0;i<n;i++)
    {
        for (size_t j = 0; j < n; j++)
        {
            int x;
            cin>>x;
            if(x==1)
            {
                adj[i+1].push_back(j+1);
                adj[j+1].push_back(i+1);
            }
        }
    }
    int nodeCnt=0;
    vector<bool> visited(n+1,false);
    dfs(s,adj,visited,nodeCnt);
    cout<<nodeCnt<<endl;
    return 0;
}