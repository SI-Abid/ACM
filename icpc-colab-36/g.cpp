#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    for(int tc=1;tc<=t;tc++)
    {
        // printf("Case %d: ",tc);
    
        int n,k;
        cin>>n>>k;
        vector<vector<int>> v(n);
        for (size_t i = 0; i < n; i++)
        {
            int x;
            cin>>x;
            v[i].resize(x);
            for (size_t j = 0; j < x; j++)
            {
                cin>>v[i][j];
            }
        }
        int ans = 0;
        for (size_t i = 0; i <  n; i++)
        {
            for (size_t j = i+1; j < n; j++)
            {
                if(v[i].size()+v[j].size() >=k)
                {
                    vector<bool> seen(k+1,false);
                    for(auto x:v[i])
                        if(x>=1 and x<=k)
                            seen[x] = true;
                    for(auto x:v[j])
                        if(x>=1 and x<=k)
                            seen[x] = true;
                    int cnt = 0;
                    if(accumulate(seen.begin(),seen.end(),0)==k)
                        ans++;
                }
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}