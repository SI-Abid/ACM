#include "bits/stdc++.h"
using namespace std;

#define ll long long
#define ull unsigned long long
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define be begin()
#define en end()
#define rb rbegin()
#define re rend()
#define all(x) (x).begin(),(x).end()
#define out cout<<setprecision(20)

typedef vector<int> vi;
typedef vector<ll> vll;
typedef set<int> si;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MOD = 1e9 + 7;
const int INF = 1e9;

int main(int argc, char* argv[])
{
    if(argc == 2 or argc == 3) freopen(argv[1], "r", stdin);
    if(argc == 3) freopen(argv[2], "w", stdout);
    ios::sync_with_stdio(false);

    int t;
    cin >> t;
    while(t--)
    {
        cin.ignore();
        int node, edge;
        cin >> node >> edge;
        vi adj[node+5];
        int dis[node+5];
        bool vis[node+5];
        for(int i = 0; i < node; i++)
        {
            adj[i].clear();
            dis[i] = INF;
            vis[i] = false;
        }
        for(int i = 0; i < edge; i++)
        {
            int a, b;
            cin >> a >> b;
            adj[a].pb(b);
            adj[b].pb(a);
        }
        // fill_n(dis, node, INF);
        dis[0] = 0;
        queue<int> q;
        q.push(0);
        while(!q.empty())
        {
            int u = q.front();
            q.pop();
            vis[u] = true;
            for(int v : adj[u])
            {
                // cout << u << " -- " << dis[u] << endl;
                if(dis[v] > dis[u] + 1)
                {
                    dis[v] = dis[u] + 1;
                    if(!vis[v])
                    {
                        q.push(v);
                    }
                }
            }
        }
        for (int i = 1; i < node; i++)
        {
            cout << dis[i] << endl;
        }
        if(t)cout<<endl;
    }    
    
    return 0;
}
