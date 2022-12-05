#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll lastDigit(ll a, ll b, ll m=1000)
{
    ll res = 1;
    while (b > 0)
    {
        if (b & 1)
        {
            res = (res * a) % m;
        }
        a = (a * a) % m;
        b >>= 1;
    }
    return res;
}
ll firstDigit(double a, double b)
{
    ll res;
    double y = b * log10(a);
    y=y-(ll)y;
    double tmp = pow(10.0,y);
    res = tmp * 100LL;
    return res;
}

signed main()
{
    ll x, y;
    int _;
    scanf("%d",&_);
    for(int tc=1;tc<=_;tc++)
    {
        // printf("Case %d: ",tc);
    
        scanf("%lld %lld",&x,&y);
        ll a = firstDigit(x,y);
        ll b = lastDigit(x,y);
        printf("%03lld...%03lld\n",a,b);
    
    }
    return 0;
}