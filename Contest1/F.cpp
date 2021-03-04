#include "bits/stdc++.h"
#define ll long long
using namespace std;

int main()
{
    ll n;
    while(true)
    {
        cin>>n;
        if(n<0)
            return 0;
        cout<<(unsigned long long)n*(n+1)/2+1<<endl;
    }
}