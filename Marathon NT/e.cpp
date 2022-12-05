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
signed main()
{
    ll x, y;
    int _;
    scanf("%d",&_);
    for(int tc=1;tc<=_;tc++)
    {
        scanf("%lld %lld",&x,&y);
        ll b = lastDigit(x,y);
        printf("%lld\n",b);
    }
    return 0;
}