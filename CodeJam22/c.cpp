#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    for(int tc=1;tc<=t;tc++)
    {
        int n;
        cin>>n;
        vector<int> v(n);
        for(int i=0;i<n;i++)
        {
            cin>>v[i];
        }
        sort(v.begin(),v.end());
        int k=1;
        for(int i=0;i<n;i++)
        {
            if(v[i]>=k)
            {
                k++;
            }
        }
        cout<<"Case #"<<tc<<": "<<k-1<<"\n";
    }
    return 0;
}