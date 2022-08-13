#include<bits/stdc++.h>
using namespace std;

#define ll long long
ll dist[10001];
vector<pair<int,ll>>adj[10001];


int main(int argc, char const *argv[])
{
    if(argc==2)
    {
        freopen(argv[1],"r",stdin);
    }
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;cin>>t;
    while(t--)
    {
        for (size_t i = 0; i < 10001; i++)
        {
            adj[i].clear();
        }
        
        int n;cin>>n;
        map<string,int>mp;
        string city;
        int edge;
        for (int i = 1; i <= n; i++)
        {
            cin>>city;
            mp[city] = i;
            cin>>edge;
            while(edge--)
            {
                int city2,cost;
                cin>>city2>>cost;
                adj[i].push_back({city2,cost});
            }
        }
        int r;
        cin>>r;
        while(r--)
        {
            string city1,city2;
            cin>>city1>>city2;
            int start = mp[city1];
            int end = mp[city2];
            for (size_t i = 0; i < 10001; i++)
            {
                dist[i] = INT_MAX;
            }
            priority_queue<pair<ll,int>>pq;
            pq.push({0,start});
            dist[start] = 0;
            while(!pq.empty())
            {
                int u = pq.top().second;
                ll cost = pq.top().first;
                pq.pop();
                if(dist[u]<cost) continue;
                for (size_t i = 0; i < adj[u].size(); i++)
                {
                    int v = adj[u][i].first;
                    ll c = adj[u][i].second;
                    if(dist[v]>dist[u]+c)
                    {
                        dist[v] = dist[u]+c;
                        pq.push({dist[v],v});
                    }
                }
            }
            cout<<dist[end]<<endl;
        }
    }
    return 0;
}