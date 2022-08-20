#include<bits/stdc++.h>
using namespace std;

using ll = long long;

ll sod(int n)
{
    ll ans = 0;
    for (int i = 2; i*i<= n; i++)
    {
        if(n%i==0)
        {
            ans+=i+n/i;
        }
    }
    return ans;
}

int main()
{
    int t;
    cin>>t;
    vector<ll> ans(1,0);
    for(int i=1;i<=15;i++)
    {
        ans.push_back(ans.back()+sod(i));
        cout<<ans.back()<<' ';   
    }
    // for(int tc=1;tc<=t;tc++)
    // {
    //     // printf("Case %d: ",tc);
    
        
    
    // }
    return 0;
}