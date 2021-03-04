#include "bits/stdc++.h"
using namespace std;

int main()
{
    // freopen("in.txt", "r", stdin);
    string x, y, z="";
    cin>>x>>y;
    for(int i=0; i<x.size(); i++)
    {
        if(x[i]<y[i])
        {
            puts("-1");
            return 0;
        }
        if(x[i]>=y[i])
        {
            z+=y[i];
        }
        // else
        // {
        //     z+=(x[i]+1);
        // }
    }
    cout<<z<<endl;
    return 0;
}