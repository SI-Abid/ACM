#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll extendedEuclid(ll a, ll b, ll &x, ll &y, int &cnt)
{
    if (b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }
    ll x1, y1;
    cnt++;
    ll d = extendedEuclid(b, a % b, x1, y1, cnt);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

signed main()
{
    int _=1;
    // cin>>_;
    for(int tc=1;tc<=_;tc++)
    {
        // printf("Case %d: ",tc);
    
        ll a,b,c,x1,y1,x2,y2;
        cin>>a>>b>>c>>x1>>x2>>y1>>y2;
        ll x,y;
        int cnt=0;
        // how many solutions are there for ax+by=c in the range [x1,x2] and [y1,y2]
        ll d=extendedEuclid(a,b,x,y,cnt);
        cout<<cnt<<endl;
    }
    return 0;
}