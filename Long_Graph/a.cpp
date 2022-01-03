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
#define all(x) (x).begin(), (x).end()
#define out cout << setprecision(20)

typedef vector<int> vi;
typedef vector<ll> vll;
typedef set<int> si;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MOD = 1e9 + 7;
const int INF = 1e9;
const int GREEN = 1;
const int BLUE = 2;
int ans;

vector<int> adj[100005];
int vis[100005];
int cnt, cnt1;

// level of a tree
// void bfs(int s)
// {
//     queue<int> q;
//     q.push(s);
//     vis[s] = GREEN;

//     while (!q.empty())
//     {
//         int u = q.front();
//         q.pop();
//         for (int v : adj[u])
//         {
//             if (!vis[v])
//             {
//                 if (vis[u] == GREEN)
//                     vis[v] = BLUE, cnt++;
//                 else
//                     vis[v] = GREEN, cnt1++;
//                 q.push(v);
//             }
//         }
//     }
// }

void dfs(int u, int col)
{
    vis[u] = col;
    // cout<<cnt<<" "<<cnt1<<" "<<col<<" "<<u<<endl;
    for (int v : adj[u])
    {
        if (vis[v])
            continue;

        if (col == GREEN)
        {
            cnt++;
            dfs(v, BLUE);
        }
        else
        {
            cnt1++;
            dfs(v, GREEN);
        }
    }
}

void clear()
{
    for (int i = 0; i < 100005; i++)
        adj[i].clear();
    memset(vis, false, sizeof vis);
    cnt = 0;
    cnt1 = 1;
    ans=0;
}

int main(int argc, char *argv[])
{
    if (argc == 2 or argc == 3)
        freopen(argv[1], "r", stdin);
    if (argc == 3)
        freopen(argv[2], "w", stdout);
    ios::sync_with_stdio(false);

    int t, it = 1;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        clear();
        int u, v;
        set<int> s;
        for (int i = 0; i < n; i++)
        {
            cin >> u >> v;
            s.insert(u);
            s.insert(v);
            adj[u].pb(v);
            adj[v].pb(u);
        }

        //bfs(1);
        for(int i:s)
            if(!vis[i])
            {
                // cout<<cnt<<" "<<cnt1<<endl;
                dfs(i, GREEN);
                ans+=max(cnt,cnt1);
                cnt=0,cnt1=1;
                // cnt1++;
            }

        // cout<<cnt<<" "<<cnt1<<endl;

        cout << "Case " << it++ << ": "<<ans<< endl;
        // printf("%d %d\n", ans[0], ans[1]);
    }
    return 0;
}