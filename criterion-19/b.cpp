#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n;cin>>n;
        vector<int> a(n);
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        map<int,bool> mp;
        for(int i=0;i<n;i++)
        {
            mp[a[i]]=true;
        }
        if(a[0]==1)
        {
            for(int i=2;i<=n+1;i++)
            {
                if(mp[i]==false)
                {
                    cout<<i<<'\n';
                    return;
                }
            }
        }
        int x=a[0];
        int m=2;
        while(true)
        {
            if(mp[x*m]==false)
            {
                cout<<x*m<<"\n";
                return;
            }
            m++;
        }
}

int main()
{
    int t;
    cin>>t;
    for(int tc=1;tc<=t;tc++)
    {
        // printf("Case %d: ",tc);
    
        solve();
    
    }
    return 0;
}