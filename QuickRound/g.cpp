#include<bits/stdc++.h>
using namespace std;
#define ll unsigned long long

ll lcm(ll a,ll b)
{
    return a*(b/__gcd(a,b));
}

int main()
{
    int n;
    cin>>n;
    ll ans;
    ll x;
    cin>>x;
    ans=x;
    n--;
    while(n-->0)
    {
        cin>>x;
        ans=lcm(ans,x);
    }
    cout<<ans<<endl;
    return 0;
}