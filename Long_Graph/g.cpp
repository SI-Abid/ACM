////////////////////////////////////////////////////////////////////////////////////////////
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define F first
#define S second
#define be begin()
#define en end()
#define rb rbegin()
#define re rend()
#define all(x) (x).begin(),(x).end()
#define out cout<<setprecision(20)
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define what_is(x) cout << #x << " is " << x << endl;
#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
#define pcase(x) cout << "Case " << x << ": ";
void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) { cerr << *it << " = " << a << endl; err(++it, args...); }

typedef vector<int> vi;
typedef vector<ll> vll;
typedef set<int> si;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MOD = 1e9 + 7;
const int INF = 1e9;

bool visited[105];
vi adj[105];

void bfs(int u, int *dist)
{
    visited[u] = true;
    queue<int> q;
    q.push(u);
    dist[u] = 0;
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        for(int v : adj[u])
        {
            if(!visited[v])
            {
                visited[v] = true;
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
}

void clear()
{
    rep(i,0,105)
    {
        adj[i].clear();
        visited[i] = false;
    }
}

int main(int argc, char* argv[])
{
    if(argc == 2 or argc == 3) freopen(argv[1], "r", stdin);
    if(argc == 3) freopen(argv[2], "w", stdout);
    ios::sync_with_stdio(false);

    int t;cin>>t;
    rep(tc,1,t+1)
    {
        int node,edge;
        cin>>node>>edge;

        clear();

        rep(i,0,edge)
        {
            int u,v;
            cin>>u>>v;
            adj[u].pb(v);
            adj[v].pb(u);
        }
        int s,t;
        cin>>s>>t;
        
        // clear();
        int distS[105];
        distS[s] = 0;
        bfs(s, distS);
        
        memset(visited,0,sizeof(visited));

        int distT[105];
        distT[t] = 0;
        bfs(t, distT);

        int ans = 0;
        rep(i,0,node)
        {
            ans=max(ans, distS[i] + distT[i]);
        }
        pcase(tc);cout<<ans<<endl;
        // cout<<ans<<endl;
    }

    return 0;
}
