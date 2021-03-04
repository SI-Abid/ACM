#include "bits/stdc++.h"
#define ll long long
using namespace std;

int main()
{
    int t;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        int n,k,p;
        cin>>n>>k>>p;
        int last = ((p%n)+k)%n;
        if(!last)   last=n;
        cout<<"Case "<<i<<": "<<last<<endl;
    }
    return 0;
}