#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int ans=0;
    if(n<100)
    {
        ans+=min(n,9);
    }   
    if(n<1000)
    {
        ans+=min(n-99,900);
    }
    if(n<100000)
    {
        ans+=min(n-9999,90000);
    }
    if(n==100000)
    {
        ans++;
    }
    cout<<ans<<endl;
    return 0;
}