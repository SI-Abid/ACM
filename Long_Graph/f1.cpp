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

int bfs(int s,int t, vector<vi> & divisors, vi &dist)
{
    dist.assign(divisors.size(),-1);
    queue<int> q;
    q.push(s);
    dist[s]=0;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(int v:divisors[u])
        {
            int now=u+v;
            if(now<=t and dist[now]==-1)
            {
                q.push(now);
                dist[now]=dist[u]+1;
                if(now==t)
                    return dist[now];
            }
        }
    }
    return dist[t];
}

int main(int argc, char* argv[])
{
    if(argc == 2 or argc == 3) freopen(argv[1], "r", stdin);
    if(argc == 3) freopen(argv[2], "w", stdout);
    ios::sync_with_stdio(false);

    // declare variables
    int t;
    vector<vector<int>> divisors(2001);
    vector<bool> isPrime(2001, true);
    vector<int> primes;
    vector<int> dist(2001, -1);

    // pre-compute prime numbers
    for(int i=2; i<2001; i++)
    {
        if(isPrime[i])
        {
            primes.pb(i);
            for(int j=i*i; j<2001; j+=i)
                isPrime[j] = false;
        }
    }

    // pre-compute divisors
    for(int i=1; i<2001; i++)
    {
        for(int j=0; j<primes.size() and primes[j]<=i; j++)
        {
            if(i%primes[j] == 0)
            {
                divisors[i].pb(primes[j]);
                if(primes[j] != i/primes[j])
                    divisors[i].pb(i/primes[j]);
            }
        }
        sort(divisors[i].begin(), divisors[i].end());
    }

    // read input
    cin >> t;
    for(int tc=1;tc<=t;tc++)
    {
        int s,t;
        cin >> s >> t;
        int ans=bfs(s,t,divisors,dist);
        pcase(tc);
        cout<<ans<<endl;
    }

    return 0;
}
/*
    generate prime array
    prime factorize each number
    call bfs from source
    update distance from source to each node
    if next node is bigger than target, return
*/