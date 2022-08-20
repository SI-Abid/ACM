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
        set<int> a;
        for (size_t i = 0; i < n; i++)
        {
            int x;
            cin>>x;
            a.insert(x);
        }
        int ans=0;
        for(auto x:a)
        {
            ans+=x+1;
        }
        cout<<max(ans,n)<<endl;
    }
    return 0;
}