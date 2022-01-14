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

bool prime[2001];
bool vis[2001];
int dist[2001];
vector<int> adj[2001];

void sieve()
{
    memset(prime, true, sizeof prime);
    prime[0] = prime[1] = false;
    for (int i = 4; i <= 2000; i += 2)
        prime[i] = false;
    for (int i = 3; i <= 2000; i += 2)
        if (prime[i])
            for (int j = i * i; j <= 2000; j += i * 2)
                prime[j] = false;
}

vi prime_factor(int n)
{
    vi res;
    for (int i = 2; i <= n; i++)
        if (prime[i] and n % i == 0)
        {
            res.pb(i);
            while (n % i == 0)
                n /= i;
        }
    return res;
}

int bfs(int parent, int t)
{
    memset(vis, false, sizeof vis);
    memset(dist, -1, sizeof dist);
    queue<int> q;
    q.push(parent);
    vis[parent] = true;
    dist[parent] = 0;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int v : adj[u])
        {
            int newnode = u+v;
            if(newnode <=t and vis[newnode] == false)
            {
                q.push(newnode);
                vis[newnode] = true;
                dist[newnode] = dist[u] + 1;
                if(newnode == t)
                    return dist[newnode];
            }
        }
    }
    return -1;
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
    sieve();
    // adj.resize(t+1);
    for (int i = 2; i <= 1050; i++)
        adj[i]=prime_factor(i);

    rep(c, 1, t + 1)
    {
        int s, n;
        cin >> s >> n;

        memset(vis, 0, sizeof vis);

        rep(i, 0, 1002)
            dist[i] = 10000;

        cout << "Case " << c << ": "<< bfs(s, n) << endl;
        // int ans = dfs(s, n);

        // if (ans >= 10000)
        // {
        //     cout << "-1\n";
        // }
        // else
        // {
        //     cout << ans << endl;
        // }
    }

    return 0;
}