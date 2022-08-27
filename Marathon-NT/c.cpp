#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    for(int tc=1;tc<=t;tc++)
    {
        printf("Case %d: ",tc);
    
        int n;
        cin>>n;
        map<int,int> m;
        for (size_t i = 0; i < n; i++)
        {
            int x;
            cin>>x;
            m[x+1]++;
        }
        long long ans=0;
        for(auto [f,s]:m)
        {
            ans+=(s/f)*f;
            if(s%f)
            {
                ans+=f;
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}