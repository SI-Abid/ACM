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
        vector<int> a(n);
        vector<int> b(n);
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        for(int i=0;i<n;i++)
        {
            cin>>b[i];
        }
        vector<long long> ans (n);
        for (size_t i = 0; i < n; i++)
        {
            ans[i] = a[i]*b[i];
        }
        long long mx=0;
        int pos;
        for (size_t i = 0; i < n; i++)
        {
            if(ans[i]>mx)
            {
                mx=ans[i];
                pos=i+1;
            }
            else if(ans[i]==mx)
            {
                if(b[i]>b[pos-1])
                {
                    mx=ans[i];
                    pos=i+1;
                }
            }
        }
        cout<<pos<<endl;
    }
    return 0;
}