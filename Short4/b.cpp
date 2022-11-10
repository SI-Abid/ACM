#include<bits/stdc++.h>
using namespace std;

signed main()
{
    int n,k;
    cin>>n>>k;
    vector<int> v(n);
    vector<int> a(k);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    for(int i=0;i<k;i++)
    {
        cin>>a[i];
    }
    int MAX = *max_element(v.begin(),v.end());
    bool flag = false;
    for(int i=0;i<n;i++)
    {
        if(v[i]==MAX)
        {
            for (size_t j = 0; j < k; j++)
            {
                if(a[j]==i+1)
                {
                    flag = true;
                    break;
                }
            }
        }
        if(flag)
        {
            break;
        }
    }
    if(flag)
    {
        cout<<"Yes";
    }
    else
    {
        cout<<"No";
    }
    return 0;
}