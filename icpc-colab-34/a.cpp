#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    for(int tc=1;tc<=t;tc++)
    {
        // printf("Case %d: ",tc);
    
        int r,c;
        cin>>r>>c;
        if(r==2 && c==2)
        {
            cout<<"Vanya\n";
            continue;
        }
        r--;
        c--;
        if( r%4 == c%3 )
        {
            cout<<"Vanya\n";
        }
        else
        {
            cout<<"Tuzik\n";
        }
    
    }
    return 0;
}