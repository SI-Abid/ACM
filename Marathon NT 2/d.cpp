#include<bits/stdc++.h>
using namespace std;

signed main()
{
    int n;
    cin>>n;
    if(n<5 or n%2)
    {
        cout<<"0\n";
    }
    else
    {
        if(n%4==0)
        {
            cout<<n/4-1<<endl;
        }
        else
        {
            cout<<n/4<<endl;
        }
    }
    return 0;
}