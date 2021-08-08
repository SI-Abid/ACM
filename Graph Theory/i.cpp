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
#define all(x) (x).begin(), (x).end()
#define out cout << setprecision(20)

typedef vector<int> vi;
typedef vector<ll> vll;
typedef set<int> si;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MOD = 1e9 + 7;
const int INF = 1e9;

bool vis[105];
vector<int> adj[105];

void dfs(int u)
{
    vis[u] = true;
    for (int v : adj[u])
        if (!vis[v])
            dfs(v);
        
}

void add_edge(int u, int v)
{
    adj[u].pb(v);
    adj[v].pb(u);
}

int main(int argc, char *argv[])
{
    if (argc == 2 or argc == 3)
        freopen(argv[1], "r", stdin);
    if (argc == 3)
        freopen(argv[2], "w", stdout);
    ios::sync_with_stdio(false);

    int t;
    cin >> t;
    cin.ignore();
    cin.ignore();
    while (t--)
    {
        memset(vis, false, sizeof(vis));
        // clear adj
        for (int i = 0; i < 100; i++)
            adj[i].clear();
        

        char c;
        cin >> c;
        int node = c - 'A';
        string jora;
        while (getline(cin, jora))
        {
            if(jora.size()==0)    
            {
                cout<<"empty line found"<<endl;
                break;
            }
            int u = jora[0] - 'A';
            int v = jora[1] - 'A';
            add_edge(u, v);
        }
        int cnt = 0;
        for (int i = 0; i <= node; i++)
        {
            if (!vis[i])
            {
                dfs(i);
                cnt++;
            }
        }

        cout << cnt << endl;
        if(t)   cout << endl;
    }

    return 0;
}
