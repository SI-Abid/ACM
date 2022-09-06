#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    for(int tc=1;tc<=t;tc++)
    {
        printf("Case %d: ",tc);
    
        int n,m;
        cin>>n>>m;
        // bool flag=false;
        int x=0, s;
        for (size_t i = 0; i < n; i++)
        {
            s=0;
            for (size_t i = 0; i < m; i++)
            {
                int xx;
                cin>>xx;
                s+=xx;
            }
            x^=s;
        }
        if(x==0)
            cout<<"Bob\n";
        else
            cout<<"Alice\n";
    
    }
    return 0;
}