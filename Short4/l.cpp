#include<bits/stdc++.h>
using namespace std;

signed main()
{
    int n,q;
    cin>>n;
    vector<int> a(n),b(n);
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        if(i)
            a[i]+=a[i-1];
    }
    for(int i=0;i<n;i++)
    {
        cin>>b[i];
        if(i)
            b[i]+=b[i-1];
    }
    cin>>q;
    while(q--)
    {
        int x,y;
        cin>>x>>y;
        x--;
        y--;
        if(a[x]==b[y])
        {
            cout<<"Yes\n";
        }
        else
        {
            cout<<"No\n";
        }
    }
    return 0;
}