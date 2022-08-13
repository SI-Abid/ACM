#include<bits/stdc++.h>
using namespace std;

int main()
{
    int a,b,c;
    cin>>a>>b>>c;
    int ans = a*c - b*c;
    cout<<((ans+b-1)/b)<<endl;
    return 0;
}