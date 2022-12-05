#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll extendedEuclid(ll a, ll b, ll &x, ll &y)
{
    if (b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }
    ll x1, y1;
    ll d = extendedEuclid(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

signed main()
{
    int _;
    cin>>_;
    for(int tc=1;tc<=_;tc++)
    {
        // printf("Case %d: ",tc);
    
        ll a,b,c;
        cin>>a>>b>>c;
        ll x,y;
        ll d=extendedEuclid(a,b,x,y);
        if(c%d)
        {
            cout<<"Case "<<tc<<": No\n";
            continue;
        }
        cout<<"Case "<<tc<<": Yes\n";
    }
    return 0;
}