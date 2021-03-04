#include "bits/stdc++.h"
#define ll long long
using namespace std;

int main()
{
    int t;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        int a, b;
        cin>>a>>b;
        int sum=0;
        while(a<=b)
        {
            if(a&1)
            {
                sum+=a;
                a+=2;
                continue;
            }
            a++;
        }
        cout<<"Case "<<i<<": "<<sum<<endl;
    }
    return 0;
}