#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    for(int tc=1;tc<=t;tc++)
    {
        printf("Case %d:",tc);
    
        int p,l;
        cin>>p>>l;
        int n = p-l;
        vector<size_t>ans;
        for(size_t i=1;i*i<=n;i++)
        {
            if(n%i==0)
            {
                if(i>l)
                    ans.push_back(i);
                if(i!=n/i and n/i > l)
                    ans.push_back(n/i);
            }
        }
        if(ans.empty())
        {
            cout<<" impossible\n";
            continue;
        }
        sort(ans.begin(),ans.end());
        for(auto x:ans)
            cout<<' '<<x;
        cout<<'\n';
    }
    return 0;
}