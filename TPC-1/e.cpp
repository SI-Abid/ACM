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


struct LCA {
    vector<int> height, euler, first, segtree;
    vector<bool> visited;
    int n;

    LCA(vector<vector<int>> &adj, int root = 0) {
        n = adj.size();
        height.resize(n);
        first.resize(n);
        euler.reserve(n * 2);
        visited.assign(n, false);
        dfs(adj, root);
        int m = euler.size();
        segtree.resize(m * 4);
        build(1, 0, m - 1);
    }

    void dfs(vector<vector<int>> &adj, int node, int h = 0) {
        visited[node] = true;
        height[node] = h;
        first[node] = euler.size();
        euler.push_back(node);
        for (auto to : adj[node]) {
            if (!visited[to]) {
                dfs(adj, to, h + 1);
                euler.push_back(node);
            }
        }
    }

    void build(int node, int b, int e) {
        if (b == e) {
            segtree[node] = euler[b];
        } else {
            int mid = (b + e) / 2;
            build(node << 1, b, mid);
            build(node << 1 | 1, mid + 1, e);
            int l = segtree[node << 1], r = segtree[node << 1 | 1];
            segtree[node] = (height[l] < height[r]) ? l : r;
        }
    }

    int query(int node, int b, int e, int L, int R) {
        if (b > R || e < L)
            return -1;
        if (b >= L && e <= R)
            return segtree[node];
        int mid = (b + e) >> 1;

        int left = query(node << 1, b, mid, L, R);
        int right = query(node << 1 | 1, mid + 1, e, L, R);
        if (left == -1) return right;
        if (right == -1) return left;
        return height[left] < height[right] ? left : right;
    }

    int lca(int u, int v) {
        int left = first[u], right = first[v];
        if (left > right)
            swap(left, right);
        return query(1, 0, euler.size() - 1, left, right);
    }
};


int main(int argc, char* argv[])
{
    if(argc == 2 or argc == 3) freopen(argv[1], "r", stdin);
    if(argc == 3) freopen(argv[2], "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;cin>>t;
    int tc=1;
    while(t--)
    {
        // clear()
        int nodes;
        cin>>nodes;
        vector<vector<int>> adj(nodes+1);
        for(int i=1;i<=nodes;i++)
        {
            int edges;
            cin>>edges;
            if(edges)
            while(edges--)
            {
                int v;
                cin>>v;
                adj[i].push_back(v);
                adj[v].push_back(i);
            }
        }
        LCA lca(adj,1);
        int q;
        cin>>q;
        cout<<"Case "<<tc++<<":\n";
        while(q--)
        {
            int u,v;
            cin>>u>>v;
            cout<<lca.lca(u,v)<<"\n";
            // vector<int> path1,path2;
            // dfs(1);
            // getPath(u,path1);
            // getPath(v,path2);
            // for(int i=1;i<=nodes;i++)
            // {
            //     cout<< i << " "<< parent[i] << endl;
            // }
            // for(auto x:path1)
            // {
            //     cout<< x<<" -> ";
            // }
            // cout<<"\n";
            // for(auto x:path2)
            // {
            //     cout<< x<<" -> ";
            // }
            // cout<<"\n";
            // int ancestor = 1;
            // for(int i=0;i<min(path1.size(),path2.size());i++)
            // {
            //     if(path1[i] == path2[i])
            //     {
            //         ancestor = path1[i];
            //     }
            //     else
            //     {
            //         cout<< ancestor << '\n';
            //         break;
            //     }
            // }
        }
    }
    return 0;
}
