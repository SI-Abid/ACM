#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    int t;
    cin>>t;
    for(int tc=1;tc<=t;tc++)
    {
        // printf("Case %d: ",tc);
    
        ll n,m;
        cin>>n>>m;
        if(n==2)
        {
            cout<<"-1\n";
            continue;
        }
        ll ans=0;
        while(n>0 and m>0)
        {
            n/=2;
            m-=n;
            ans++;
        }
        if(m>0)
        {
            ans+=m;
        }
        cout<<ans<<"\n";
    }
    return 0;
}