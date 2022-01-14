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
const int dx[]={0,0,1,-1};
const int dy[]={1,-1,0,0};
const int fx[]={1,1,1,1,0,-1,-1,-1};
const int fy[]={1,0,-1,0,1,1,-1,-1};

ll distP[30005];
ll distQ[30005];
vector<pii> adj[30005];
bool vis[30005];
int p,q,cost;

void dfs1(int node)
{
    vis[node] = true;
    for(auto [val,dis]: adj[node])
    {
        if(!vis[val])
        {
            distP[val] = dis + distP[node];
            if(distP[val]>cost)
            {
                q = val;
                cost = distP[val];
            }
            dfs1(val);
        }
    }
}

void dfs2(int node)
{
    vis[node] = true;
    for(auto [val,dis]: adj[node])
    {
        if(!vis[val])
        {
            distQ[val] = dis + distQ[node];
            if(distQ[val]>cost)
            {
                p = val;
                cost = distQ[val];
            }
            dfs2(val);
        }
    }
}

void clear()
{
    memset(vis,false,sizeof vis);
    memset(distP,0,sizeof distP);
    memset(distQ,0,sizeof distQ);
    for(int i=0;i<30005;i++)
    {
        adj[i].clear();
    }
}

int main(int argc, char* argv[])
{
    if(argc == 2 or argc == 3) freopen(argv[1], "r", stdin);
    if(argc == 3) freopen(argv[2], "w", stdout);
    ios::sync_with_stdio(false);

    int t;cin>>t;
    rep(c,1,t+1)
    {
        clear();
        int nodes,edges;
        cin>>nodes;
        edges=nodes-1;
        
        rep(i,0,edges)
        {
            int a,b,c;
            cin>>a>>b>>c;
            adj[a].pb({b,c});
            adj[b].pb({a,c});
        }

        cost=0;
        memset(vis, false, sizeof vis);
        dfs2(0);
        
        cost=0;
        memset(distP, 0, sizeof distP);
        memset(vis, false, sizeof vis);
        dfs1(p);
        
        cost=0;
        memset(distQ, 0, sizeof distQ);
        memset(vis, false, sizeof vis);
        dfs2(q);
        // memset(vis, false, sizeof vis);
        // memset(distP, 0, sizeof distP);

        pcase(c);
        cout<<endl;
        rep(node,0,nodes)
        {
            cout<<max(distP[node],distQ[node])<<endl;
        }
        
    }

    return 0;
}