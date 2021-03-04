#include<bits/stdc++.h>
#define ll long long int
#define pb push_back
using namespace std;
int main()
{
    int t, m=0, p=0,a,b;
    cin>>t;
    while(t--)
    {
        cin>>a>>b;
        p=p-a+b;
        m=max(m,p);
    }
    cout<<m<<endl;
    return 0;
}