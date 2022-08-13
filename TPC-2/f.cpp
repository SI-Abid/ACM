////////////////////////////////////////////////////////////////////////////////////////////
#include <bits/stdc++.h>
using namespace std;

#define cls system("clear");
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
const int fx[]={0,1,1,1,0,-1,-1,-1};
const int fy[]={1,1,0,-1,-1,-1,0,1};

vector<int> edges[10005];
bool vis[10005];
int disc[10005];
int counter;
int mini[10005];
set<int> cut_node;

void add_edge(int u, int v)
{
    edges[u].pb(v);
    edges[v].pb(u);
}

void dfs(int u, int pn)
{
    vis[u] = true;
    disc[u] = mini[u] = counter++;
    int cc = 0;

    for(auto v : edges[u])
    {
        if(v == pn) continue;
        if(vis[v]) 
        {
            mini[u] = min(mini[u], disc[v]);
        }
        else
        {
            cc += 1;
            dfs(v, u);
            mini[u] = min(mini[u], mini[v]);

            if(disc[u] <= mini[v] && pn != -1)
            {
                cut_node.insert(u);
            }
        }
    }
    if(cc > 1 && pn == -1) 
    {
        cut_node.insert(u);
    }
}

void clear()
{
    for(int i = 0; i < 10005; i++)
    {
        edges[i].clear();
        vis[i] = false;
        disc[i] = 0;
        mini[i] = 0;
    }
    counter = 0;
    cut_node.clear();
}

int main(int argc, char* argv[])
{
    if(argc == 2 or argc == 3) freopen(argv[1], "r", stdin);
    if(argc == 3) freopen(argv[2], "w", stdout);
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int t,tc=1;
    cin>>t;
    while(t--)
    {
        cout<< "Case " << tc++ << ": ";
        int n,m;
        cin>>n>>m;
        clear();
        while(m--)
        {
            int u,v;
            cin>>u>>v;
            add_edge(u,v);
        }
        for (int i = 1; i <= n; i++)
        {
            if(!vis[i])
            {
                dfs(i, -1);
            }
        }
        cout<<cut_node.size()<<'\n';
    }
    

    return 0;
}
