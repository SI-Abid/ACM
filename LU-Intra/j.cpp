#include<bits/stdc++.h>
using namespace std;

int main()
{
    bool ar[400002]={0};
    int t;
    cin>>t;
    t+=t;
    int a,b,cnt=0;
    while(t--)
    {
        cin>>a;
        if(ar[a]==0)
            ar[a]=1;
        else
            ar[a]=0;
    }
    for(int i=0;i<400002;i++)
        cnt+=ar[i];

    cout<< cnt <<endl;
    return 0;
}