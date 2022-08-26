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
ll cost[105],n,maxDis,dp[10005][1005];
bool vis[1005];
map< ll, pair< ll,ll > >dis;
vector< pair< ll,ll > >g[105];

ll rec(ll pos, ll costs){
    if(pos == n+1){
        cout<<"->"<<costs<<ed;
        if(costs <= maxDis)return 0;
        else return 1e18;
    }

    if(dp[pos][costs] != -1)return dp[pos][costs];
    vis[pos] = true;
    ll ans=INT_MAX;
    for(auto it : g[pos]){
        if(vis[it.F])continue;
        ll dist = ceil(sqrt((dis[pos].F - dis[it.F].F)*(dis[pos].F - dis[it.F].F) + (dis[pos].S - dis[it.F].S)*(dis[pos].S - dis[it.F].S)));
        if(dist+costs<=maxDis){
            ans = min(ans, (dist*it.S)+ rec(it.F, costs + dist));
        }
    }
    return dp[pos][costs]=ans;
}


int main()
{
    FastRead;
    ll t,m,i,j,x,y,x1,y1,k,c0;
    memset(dp, -1, sizeof(dp));
    cin>>x>>y>>x1>>y1>>maxDis>>c0>>t;
    for(i=0;i<t;i++)
    {
        cin>>cost[i];

    }
    g[0].pb({n+1,c0});
    g[n+1].pb({0,c0});
    dis[0] = {x,y};
    dis[n+1] = {x1,y1};
    cin>>n;
    for(i=1;i<=n;i++){
        ll a,b;
        cin>>a>>b;
        dis[i] = {a,b};
        g[0].pb({i,c0});
        g[i].pb({0,c0});
        g[n+1].pb({i,c0});
        g[i].pb({n+1,c0});
        cin>>k;
        for(j=0;j<k;j++){
            ll c,d;
            cin>>c>>d;
            g[i].pb({c,cost[d-1]});
            g[c].pb({i,cost[d-1]});
        }
    }

    cout<<rec(0,0)<<ed;

    return 0;
}




