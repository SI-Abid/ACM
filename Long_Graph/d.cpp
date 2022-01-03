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

vector<int> adj[100005];
vector<int> reach(100005);

void dfs(int u)
{
    for (int v : adj[u])
    {
        reach[v] = reach[u]+1;
        dfs(v);
    }
}

void clear()
{
    for (int i = 0; i < 100005; i++)
    {
        adj[i].clear();
        reach[i] = 1;
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
        int k,n,m;
        cin>>k>>n>>m;
        vector<int> people(k);
        for(int i=0;i<k;i++)
        {
            cin>>people[i];
        }
        for(int i=0;i<m;i++)
        {
            int a,b;
            cin>>a>>b;
            adj[a].pb(b);
        }
        for(int x:people)
        {
            dfs(x);
        }
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            if(reach[i]>=k)
            {
                ans++;
            }
        }
        cout<<"Case "<<c<<": "<<ans<<endl;
    }

    return 0;
}
