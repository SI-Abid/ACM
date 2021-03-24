#include "bits/stdc++.h"
#define ll long long
using namespace std;

ll rev(ll);

int main()
{
    // freopen("in.txt","r",stdin);
    int t;
    for(cin>>t;t;t--)
    {
        ll x, r, itr=0;
        cin>>x;
        while(true)
        {
            r=rev(x);
            if(x==r)
                break;
            x+=r;
            itr++;
        }
        cout<<itr<<" "<<x<<endl;
    }
    return 0;
}

ll rev(ll n)
{
    ll r=0;
    while(n)
    {
        r*=10;
        r+=n%10;
        n/=10;
    }
    return r;
}