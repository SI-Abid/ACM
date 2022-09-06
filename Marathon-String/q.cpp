#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    for(int tc=1;tc<=t;tc++)
    {
        // printf("Case %d: ",tc);
    
        int n;
        cin>>n;
        int ans=(n/7)*9;
        int rem=n%7;
        switch (rem)
        {
        case 5:
            ans++;
        case 4:
            ans++;
        default:
            ans+=rem;
            break;
        }
        cout<<ans<<'\n';
    }
    return 0;
}