#include<bits/stdc++.h>
#define ll long long int
#define F first
#define S second
#define pb push_back
#define ed '\n'
#define pi 2 * acos(0.0)
#define mod 1000000007
#define Case(x) cout<<"Case "<<x<<": ";
#define FastRead ios_base::sync_with_stdio(false);cin.tie(0),cout.tie(0)
using namespace std;
ll cost[105];
map< ll, pair< ll,ll > >dis;
vector< pair< ll,ll > >g[105];


int main()
{
    FastRead;
    ll t,n,m,i,j,x,y,x1,y1,maxDis,c0;
    cin>>x>>y>>x1>>y1>>maxDis>>c0;>>t;
    for(i=0;i<t;i++)
    {
        cin>>cost[i];

    }
    g[0].pb({n+1,c0});
    g[n+1].pb({0,c0});
    cin>>n;
    for(i=1;i<=n;i++){
        cin>>a>>b;
        dis[i] = {a,b};
        g[0].pb({i,c0});
        g[i].pb({0,c0});
        g[n+1].pb({i,c0});
        g[i].pb({n+1,c0});
        cin>>k;
        for(j=0;j<k;j++){
            cin>>c>>d;
            g[i].pb({c,cost[d-1]});
            g[c].pb({i,cost[d-1]});
        }
    }

    }

    return 0;
}




