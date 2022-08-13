#include<bits/stdc++.h>
using namespace std;

vector<int> adj[1000002];
bool vis[1000002];

void dfs(int u)
{
    vis[u] = true;
    for(int i=0;i<adj[u].size();i++)
    {
        int v = adj[u][i];
        if(!vis[v])
        {
            dfs(v);
        }
    }
}

void clear()
{
    for(int i=0;i<1000002;i++)
    {
        adj[i].clear();
        vis[i] = false;
    }
}

int main()
{
    int n,k;
    cin>>n>>k;
    // set<int>s;
    while(k--)
    {
        int a,b;
        cin>>a>>b;
        if(a>b)
        {
            swap(a,b);
        }
        if(a+b==n+1)
        {
            s.insert(a);
            s.insert(b);
        }
    }
    return 0;
}