#include<bits/stdc++.h>
using namespace std;
#define ll long long

int sod(ll n)
{
    int ans=0;
    while(n>0)
    {
        ans+=(n%10);
        n/=10;
    }
    return ans;
}

int main()
{
    ll n;
    cin>>n;
    ll step;
    for(ll st=1000000000000000000;st>0;st/=10)
    {
        if(n/st)
        {
            step=st;
            break;
        }
    }
//    cout<<step<<endl;
    ll stt = (n+1)/step;
//    cout<<stt<<endl;
    cout<<sod(stt*step-1)<<endl;
    return 0;
}

