#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    int ans=n/m;
    if(n%m)
        ans++;
    
    cout<<ans<<endl;
    return 0;
}