#include<bits/stdc++.h>
using namespace std;
#define ll long long

int m = 10000009;

ll binPow(ll a, ll n)
{
    if(n<=0)
        return 1;
    ll ans = 1;
    // cout<<a<<" "<<n<<endl;
    if(n&1)
        return a*binPow((a*a)%m,n/2)%m;

    return binPow((a*a)%m, n/2);
}

int main()
{
    ll a = 900;
    ll p = 9800000;
    ll ans = 1;
    while(p--)
    {
        ans = (ans * a) % m;
    }
    cout<< ans<<endl;
    cout<<binPow(900,9800000)<<endl;
    return 0;
}