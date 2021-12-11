#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long n,k;
    cin>>n>>k;
    vector<long long> a(n);
    for(long long i=0;i<n;i++)
    {
        cin>>a[i];
    }
    if(n<=k)
    {
        cout<<0<<endl;
        return 0;
    }
    long long ans=0;
    sort(a.rbegin(),a.rend());
    for(long long i=k;i<n;i++)
    {
        ans+=a[i];
    }
    cout<<ans<<endl;
    return 0;
}