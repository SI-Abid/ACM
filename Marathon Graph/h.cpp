#include<bits/stdc++.h>
using namespace std;

signed main()
{
    map<string,vector<string>> adj;
    map<string,bool> vis;
    map<string,int> dist;
    int dx[]={2,2,-2,-2,1,1,-1,-1};
    int dy[]={1,-1,1,-1,2,-2,2,-2};
    for(int i=1;i<=8;i++)
    {
        for(int j=1;j<=8;j++)
        {
            string s="";
            s+=char(i+'a'-1);
            s+=char(j+'0');
            for(int k=0;k<8;k++)
            {
                int x=i+dx[k];
                int y=j+dy[k];
                if(x>=1 and x<=8 and y>=1 and y<=8)
                {
                    string t="";
                    t+=char(x+'a'-1);
                    t+=char(y+'0');
                    adj[s].push_back(t);
                    // adj[t].push_back(s);
                }
            }
        }
    }
    string x,y;
    while (cin>>x>>y)
    {
        queue<string> q;
        q.push(x);
        vis[x]=true;
        while(!q.empty())
        {
            string w=q.front();
            q.pop();
            for(auto z:adj[w])
            {
                if(!vis[z])
                {
                    vis[z]=true;
                    dist[z]=dist[w]+1;
                    q.push(z);
                }
            }
        }
        cout<<"To get from "<<x<<" to "<<y<<" takes "<<dist[y]<<" knight moves."<<'\n';
        vis.clear();
        dist.clear();

    }
    return 0;
}