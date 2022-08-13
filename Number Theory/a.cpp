#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        ll a,b;
        cin>>a>>b;
        ll gcd=__gcd(a,b);
        ll lcm=a*b/gcd;
        cout<<gcd<<" "<<lcm<<endl;
    }
    return 0;
}