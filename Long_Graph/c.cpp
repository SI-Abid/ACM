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

vector<pii> adj[30005];
bool visited[30005];
int save[30005];
int cost, leaf;

void dfs(int node)
{
    visited[node] = true;
    for(auto [val,dis]: adj[node])
    {
        if(!visited[val])
        {
            save[val] = dis + save[node];
            if(save[val]>cost)
            {
                leaf = val;
                cost = save[val];
            }
            dfs(val);
        }
    }
}

int main(int argc, char* argv[])
{
    if(argc == 2 or argc == 3) freopen(argv[1], "r", stdin);
    if(argc == 3) freopen(argv[2], "w", stdout);
    ios::sync_with_stdio(false);

    int t;cin>>t;
    rep(c,0,t)
    {
        int nodes,edges;
        cin>>nodes;
        edges=nodes-1;
        rep(i,0,nodes)
        {
            adj[i].clear();
        }
        rep(i,0,edges)
        {
            int a,b,c;
            cin>>a>>b>>c;
            adj[a].pb({b,c});
            adj[b].pb({a,c});
        }

        cost=0;
        dfs(0);

        memset(visited, false, sizeof visited);
        memset(save, 0, sizeof save);
        
        cost=0;
        dfs(leaf);
        memset(visited, false, sizeof visited);
        memset(save, 0, sizeof save);
        // memset(adj, 0, sizeof adj);

        cout<<"Case "<<c+1<<": "<<cost<<endl;
    }

    return 0;
}
