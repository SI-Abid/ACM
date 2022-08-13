#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<ll,ll>

void dijkstra(ll s, vector<vector<pii>> &adj, vector<ll> &dist)
{
    priority_queue<pii> pq;
    pq.push({0, s});
    dist[s] = 0;
    while (!pq.empty())
    {
        ll u = pq.top().second;
        pq.pop();
        // ll u = cur.second;
        for (auto v : adj[u])
        {
            ll d = dist[u] + v.second;
            if (d < dist[v.first])
            {
                dist[v.first] = d;
                pq.push({-d, v.first});
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    int tt;cin>>tt;
    while (tt--)
    {
        ll n,m,k,s,t;
        cin>>n>>m>>k>>s>>t;
        vector<vector<pair<ll,ll>>> adj1(100005,vector<pair<ll,ll>>());
        vector<vector<pair<ll,ll>>> adj2(100005,vector<pair<ll,ll>>());
        vector<ll> dist1(100005,1e18);
        vector<ll> dist2(100005,1e18);
        for (ll i = 0,u,v,w; i < m; i++)
        {
            cin>>u>>v>>w;
            adj1[u].push_back({v,w});
            adj2[v].push_back({u,w});
        }
        
        dijkstra(s,adj1,dist1);
        dijkstra(t,adj2,dist2);

        ll ans = dist1[t];

        for (ll i = 0,u,v,w; i < k; i++)
        {
            cin>>u>>v>>w;
            ans=min({ans, dist1[u]+dist2[v]+w, dist1[v]+dist2[u]+w});
        }
        if(ans==1e18)
        {
            cout<<"-1\n";
        }
        else
        {
            cout<<ans<<'\n';
        }
        // cout<<INT64_MAX<<'\n';
    }   
    return 0;
}