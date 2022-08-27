#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    for(int tc=1;tc<=t;tc++)
    {
        printf("Case %d: ",tc);
    
        int n, d;
        cin>>n>>d;
        int ans=0;
        int rem=0;
        while (true)
        {
            rem = (rem*10+d)%n;
            ans++;
            if(rem==0)
            {
                break;
            }
        }
        cout<<ans<<'\n';
    
    }
    return 0;
}