#include<bits/stdc++.h>
using namespace std;


int main()
{
    int d,n;
    cin>>d>>n;
    n=n+((n-1)/99);
    
    while(d-->0)
        n*=100;

    cout<< n <<endl;
    return 0;
}