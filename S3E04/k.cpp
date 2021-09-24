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
#define rb rbegin()
#define re rend()
#define all(x) (x).begin(),(x).end()
#define out cout<<setprecision(20)

typedef vector<int> vi;
typedef vector<ll> vll;
typedef set<int> si;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MOD = 1e9 + 7;
const int INF = 1e9;

vector<pii> egdes[100005];

void add_edge(int u, int v, int n)
{
    edges[u].pb({v, n});
    edges[v].pb({u, n});
}

int main(int argc, char* argv[])
{
    if(argc == 2 or argc == 3) freopen(argv[1], "r", stdin);
    if(argc == 3) freopen(argv[2], "w", stdout);
    ios::sync_with_stdio(false);

    int n,m,q;
    cin>>n>>m>>q;
    for (int i = 0; i < m; i++)
    {
        int x,y;
        cin>>x>>y;
        add_edge(x,y,i+1);
    }

    while(q--)
    {
        //TIMES UP
    }
        
    
    return 0;
}
