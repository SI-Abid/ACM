#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<pair>

using namespace std;

#define ll long long
#define MOD 1000000007
#define pb push_back


vector<int>adj[100002];
bool visited[100002];
char label[100002];

void dfs(int u)
{
    visited[u]=true;
    for(int i=0;i<adj[u].size();i++)
    {
        int v=adj[u][i];
        if(!visited[v])
        {
            dfs(v);
        }
    }

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        for(int i=1;i<n;i++)
        {
            int u,v;
            cin>>u>>v;
            adj[u].pb(v);
            adj[v].pb(u);
        }
        int s;
        for(int i=1;i<=n;i++)
        {
            cin>>label[i];
            if(label[i]=='t')
                s=i;
        }
        dfs(s);
    }
}