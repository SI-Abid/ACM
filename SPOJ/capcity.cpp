#include<bits/stdc++.h>
using namespace std;

vector<int> adj[100005];
vector<int> rev[100005];
bool vis[100005];
stack<int> st;
vector<int> comp;
vector<vector<int> > scc;
vector<int> adj_scc[100005];
vector<int> comp_map;

void dfs1(int u)
{
    vis[u]=true;
    for(auto v:adj[u])
    {
        if(!vis[v])
        {
            dfs1(v);
        }
    }
    st.push(u);
}

void dfs2(int u)
{
    vis[u]=true;
    for(auto v:rev[u])
    {
        if(!vis[v])
        {
            dfs2(v);
        }
    }
    comp.push_back(u);
}

void dfs3(int u)
{
    vis[u]=true;
    for(auto v:adj_scc[u])
    {
        if(!vis[v])
        {
            dfs3(v);
        }
    }
    comp.push_back(u);
}

void clear()
{
    for(int i=1;i<=100000;i++)
    {
        adj[i].clear();
        vis[i]=false;
    }
}

int main()
{
    comp_map.resize(100005,0);
    int n,m;
    cin>>n>>m;
    while(m--)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        rev[v].push_back(u);
    }
    for(int i=1;i<=n;i++)
    {
        if(!vis[i])
        {
            dfs1(i);
        }
    }
    memset(vis,0,sizeof(vis));
    int cnt=0;
    while(!st.empty())
    {
        int u=st.top();
        st.pop();
        if(!vis[u])
        {
            cnt++;
            dfs2(u);
            
            scc.push_back(comp);
            for(auto v:comp)
            {
                comp_map[v]=cnt;     // mapping which node belongs to which scc
            }
            comp.clear();
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(auto u:adj[i])
        {
            if(comp_map[i]!=comp_map[u])
            {
                adj_scc[comp_map[i]-1].push_back(comp_map[u]-1);    // new adj list for scc
            }
        }
    }
    comp.clear();
    memset(vis,0,sizeof(vis));
    for(int x=0;x<scc.size();x++)
    {
        if(!vis[x])
        {
            dfs3(x);
        }
    }
    ////////////////////////////////////////////////////////////////////
    // for(int i=0;i<scc.size();i++)
    // {
    //     if(scc[i].size()>0)
    //     {
    //         cout<<i<<" -> [ ";
    //         for(auto x:scc[i])
    //         {
    //             cout<<x<<" ";
    //         }
    //     }
    //     cout<<"]\n";
    // }
    // for(int i=0;i<scc.size();i++)
    // {
    //     cout<<i<<" -> [ ";
    //     for(auto x:adj_scc[i])
    //     {
    //         cout<<x<<" ";
    //     }
    //     cout<<"]\n";
    // }
    vector<int> ans=scc[comp[0]];
    cout<<ans.size()<<"\n";
    sort(ans.begin(),ans.end());
    for(auto x:ans)
    {
        cout<<x<<" ";
    }
    cout<<"\n";
    return 0;
}
/*


6 7
1 2
2 3
3 1
2 4
4 5
5 6
6 4


*/