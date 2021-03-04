#include<bits/stdc++.h>
#define ll long long int
#define pb push_back
using namespace std;
int main()
{
    int t;
    int cnt=0;
    for(cin>>t;t;t--)
    {
        int a,b,c;
        cin>>a>>b>>c;
        if(a+b+c>1)
            cnt++;
    }
    cout<<cnt<<endl;
    return 0;
}