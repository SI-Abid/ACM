// connected component in a directed graph
#include<bits/stdc++.h>
using namespace std;

struct Graph
{
    int nodes, edges;
    vector<vector<int>> adj;
    vector<bool> visited;
    stack<int> st;
    Graph(int n, int m)
    {
        nodes = n;
        edges = m;
        adj.resize(n+1);
        visited = vector<bool>(n, false);
        comp = 0;
    }
    void addEdges()
    {
        int u, v;
        for(int i = 0; i < edges; i++)
        {
            cin >> u >> v;
            adj[u].push_back(v);
        }
    }
    void dfs(int u)
    {
        visited[u] = true;
        for(int v : adj[u])
        {
            if(!visited[v])
                dfs(v);
        }
    }
    
};


int main()
{
    #ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
    #endif

    int t;
    scanf("%d", &t);
    for(int tc=1;tc<=t;tc++)
    {
        printf("Case %d: ",tc);
    
        int n, m;
        scanf("%d %d", &n, &m);
        Graph g(n, m);
        g.addEdges();
        g.countComp();
        printf("%d\n", g.comp);
    
    }
    return 0;
}