#include<bits/stdc++.h>
using namespace std;

int sumOfDigits(int n){
    int sum = 0;
    while(n){
        sum += n%10;
        n /= 10;
    }
    return sum;
}

signed main()
{
    int a,b;
    cin>>a>>b;
    vector<vector<int>> adj(10000);
    queue<int> q;
    q.push(a);
    while(!q.empty())
    {
        int w=q.front();
        q.pop();
        int x,y,z;
        x=w*3;
        y=w+sumOfDigits(w);
        z=w-2;
        if(x<10000 and adj[x].empty())
        {
            adj[x].push_back(w);
            adj[w].push_back(x);
            q.push(x);
        }
        if(y<10000 and adj[y].empty())
        {
            adj[y].push_back(w);
            adj[w].push_back(y);
            q.push(y);
        }
        if(z>=0 and adj[z].empty())
        {
            adj[z].push_back(w);
            adj[w].push_back(z);
            q.push(z);
        }
    }
    vector<bool> vis(10000,false);
    vector<int> dist(10000,0);
    q.push(a);
    vis[a]=true;
    while(!q.empty())
    {
        int w=q.front();
        q.pop();
        for(auto x:adj[w])
        {
            if(!vis[x])
            {
                vis[x]=true;
                dist[x]=dist[w]+1;
                q.push(x);
            }
        }
    }
    cout<<dist[b];
    return 0;
}