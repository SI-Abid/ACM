#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;cin>>t;
    while(t--)
    {
        int n;cin>>n;
        vector<int> v(n);
        for(int i=0;i<n;i++)
        {
            cin>>v[i];
        }
        int local,global;
        local=global=0;
        for (int i = 0; i < n-1; i++)
        {
            for (int j = i+1; j < n; j++)
            {
                if(v[i]>v[j])
                {
                    global++;
                }
            }
        }
        for (int i = 0; i < n-1; i++)
        {
            if(v[i]>v[i+1])
            {
                local++;
            }
        }
        cout<<(global==local?"YES\n":"NO\n");
    }
    return 0;
}