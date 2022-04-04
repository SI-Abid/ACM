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
#define all(x) (x).begin(), (x).end()
#define out cout << setprecision(20)
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define what_is(x) cout << #x << " is " << x << endl;
#define error(args...)                           \
    {                                            \
        string _s = #args;                       \
        replace(_s.begin(), _s.end(), ',', ' '); \
        stringstream _ss(_s);                    \
        istream_iterator<string> _it(_ss);       \
        err(_it, args);                          \
    }
#define pcase(x) cout << "Case " << x << ": ";
void err(istream_iterator<string> it)
{
}
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args)
{
    cerr << *it << " = " << a << endl;
    err(++it, args...);
}

typedef vector<int> vi;
typedef vector<ll> vll;
typedef set<int> si;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MOD = 1e9 + 7;
const ll INF = 1e18;
const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};
const int fx[] = {0, 1, 1, 1, 0, -1, -1, -1};
const int fy[] = {1, 1, 0, -1, -1, -1, 0, 1};

vector<ll> adj[100001];
bool visited[100001];
ll node[100001];

pll dfs(int u)
{
    visited[u] = true;
    // cout<<node[u]<<" -> ";
    pll ret = {0, 0};
    ret.F = node[u];
    ll mn = INF;
    for (int v : adj[u])
    {
        if (visited[v])
            continue;
        pll tmp = dfs(v);
        ret.S += tmp.S;
        // printf("at node %lld %lld\n",node[u],ret.S);
        mn = min(mn, tmp.F);
    }

    if(mn > node[u] && mn!=INF){
        // cout<<"update "<<node[u]<<' '<<mn<<endl;
        node[u]=mn;
    }

    if (mn < node[u]){
        // cout<<"replacing "<<node[u]<<' '<<mn<<' '<<ret.S<<endl;
        ret.S += node[u] - mn;
        // cout<<"after replace "<<ret.S<<endl;
    }
    
    if (adj[u].size() == 0)
    {
        ret.F = node[u];
        ret.S = node[u];
    }
    //  printf("{%lld} [%lld %lld]\n", node[u], ret.F, ret.S);
    ret.F=node[u];
    return ret;
}

int main(int argc, char *argv[])
{
    if (argc == 2 or argc == 3)
        freopen(argv[1], "r", stdin);
    if (argc == 3)
        freopen(argv[2], "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    for (int tc = 1; tc <= t; tc++)
    {
        int n;
        cin >> n;
        // node.resize(n+1);
        rep(i, 0, n) cin >> node[i + 1];
        rep(i, 0, n + 1) adj[i].clear();
        for (int i = 1, idx; i <= n; i++)
        {
            cin >> idx;
            adj[idx].pb(i);
        }
        // print graph
        // rep(i,0,n+1)
        // {
        //     cout<<i<<" -> ";
        //     for(int v:adj[i])
        //         cout<<v<<" ";
        //     cout<<endl;
        // }
        memset(visited, false, sizeof(visited));
        pll ans = dfs(0);
        cout << "Case #" << tc << ": " << ans.S;
        if (tc != t)
            cout << "\n";
        memset(node, 0, sizeof(node));
    }

    return 0;
}
