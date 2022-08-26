#include<bits/stdc++.h>
using namespace std;

void dijkstra(vector<vector<pair<int, int>>> &graph, pair<int,int> src, int n)
{
    priority_queue<pair<int,int>> pq;
    pq.push({0, src});
    vector<int> dist(n, INT_MAX);
    dist[src.first] = 0;
    while (!pq.empty())
    {
        pair<int, int> top = pq.top();
        pq.pop();
        int u = top.second.first;
        int v = top.second.second;
        if (dist[u] < top.first)
            continue;
        for (auto it : graph[u])
        {
            if (dist[it.first] > dist[u] + it.second)
            {
                dist[it.first] = dist[u] + it.second;
                pq.push({dist[it.first], {it.first, v}});
            }
        }
    }
}

int main()
{
    pair<int,int> src, dst;
    cin>>src.first>>src.second;
    cin>>dst.first>>dst.second;
    int b,c0;
    cin>>b>>c0;
    int t;cin>>t;
    vector<int> modes(t);
    for(int i=0;i<t;i++)
    {
        cin>>modes[i];
    }
    vector<pair<int,int>> station;
    int n;cin>>n;
    vector<vector<pair<int,int>>> link(n+1);
    for(int i=0;i<n;i++)
    {
        int x,y;cin>>x>>y;
        station.pb({x,y});
        int num;cin>>num;
        for(int j=0;j<num;j++)
        {
            int to,mode;
            cin>>to<<mode;
            link[i].pb({to-1,modes[mode-1]});
            link[to-1].pb({i,modes[mode-1]});
        }
    }
    pair<int,int> src2,dst2;
    int src_d,dst_d;
    src_d=dst_d=INT_MAX;
    for(int i=0;i<n;i++)
    {
        int d=abs(station[i].first-src.first)+abs(station[i].second-src.second);
        if(d<src_d)
        {
            src2=station[i];
            src_d=d;
        }
        d = abs(station[i].first-dst.first)+abs(station[i].second-dst.second);
        if(d<dst_d)
        {
            dst2=station[i];
            dst_d=d;
        }
    }

    return 0;
}