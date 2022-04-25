#include<bits/stdc++.h>
using namespace std;


int main()
{
    // freopen("in","r",stdin);
    // freopen("out","w",stdout);
    int tc=1;
    int n;
    while(cin>>n)
    {
        map<string,int> forward;
        string reverse[1001];
        vector<int> adj[1001];
        vector<int> ans;
        for(int i=0;i<n;i++)
        {
            string s;
            cin>>s;
            forward[s]=i;
            reverse[i]=s;
        }
        int m;
        cin>>m;
        vector<int> in_degree(n,0);
        for(int i=0;i<m;i++)
        {
            string s,t;
            cin>>s>>t;
            int u=forward[s];
            int v=forward[t];
            adj[u].push_back(v);
            in_degree[v]++;
        }
        multiset<int> q;
        for(int i=0;i<n;i++)
        {
            if(in_degree[i]==0)
            {
                q.insert(i);
            }
        }
        while(!q.empty())
        {
            int u=*q.begin();
            q.erase(q.begin());
            ans.push_back(u);
            for(int i=0;i<adj[u].size();i++)
            {
                int v=adj[u][i];
                in_degree[v]--;
                if(in_degree[v]==0)
                {
                    q.insert(v);
                }
            }
        }

        cout<<"Case #"<<tc++<<": Dilbert should drink beverages in this order:";
        for(auto i:ans)
        {
            cout<<" "<<reverse[i];
        }
        cout<<".\n\n";
    }
    return 0;
}