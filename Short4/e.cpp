#include<bits/stdc++.h>
using namespace std;

signed main()
{
    int n,q;
    cin>>n>>q;
    vector<int> v(n);
    iota(v.begin(),v.end(),1);
    vector<int> pos(n+1);
    for(int i=0;i<n;i++)
    {
        pos[v[i]]=i;
    }

    while(q--)
    {
        int x;
        cin>>x;
        if(pos[x]==n-1)
        {
            swap(v[pos[x]],v[pos[x]-1]);
            pos[x]--;
            pos[v[pos[x]+1]]++;
        }
        else
        {
            swap(v[pos[x]],v[pos[x]+1]);
            pos[x]++;
            pos[v[pos[x]-1]]--;
        }
    }
    for(int i=0;i<n;i++)
    {
        cout<<v[i]<<" ";
    }
    return 0;
}