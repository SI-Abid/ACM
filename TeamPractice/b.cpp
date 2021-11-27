#include<iostream>
using namespace std;

#define MOD 1000000007
#define ll long long
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        ll a,b,c,d;
        cin>>a>>b>>c>>d;
        ll aa = (a%MOD) * (b%MOD);
        ll bb = (c%MOD) * (d%MOD);
        cout<<((aa-bb)+MOD)%MOD<<endl;
    }
    return 0;
}
