#include<bits/stdc++.h>
using namespace std;

signed main()
{
    int n;
    cin>>n;
    map<int,int> m;
    while(n--)
    {
        int q;
        cin>>q;
        if(q==1)
        {
            int x;
            cin>>x;
            m[x]++;
        }
        else if(q==2)
        {
            int x,c;
            cin>>x>>c;
            if(m[x]>c)
            {
                m[x]-=c;
            }
            else
            {
                m.erase(x);
            }
        }
        else
        {
            int x=m.begin()->first;
            int y=m.rbegin()->first;
            cout<<y-x<<endl;
        }
    }
    return 0;
}