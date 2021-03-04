#include "bits/stdc++.h"
#define ll long long
using namespace std;

int main()
{
    int t;
    for(cin>>t;t;t--)
    {
        int a, b;
        cin>>a>>b;
        if(a>b)
            puts(">");
        else if(a<b)
            puts("<");
        else 
            puts("=");
    }
    return 0;
}