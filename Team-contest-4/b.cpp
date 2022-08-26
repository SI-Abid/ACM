#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    map<string,int>mp;
    int total=n;
    while(n--)
    {
        string s;
        cin>>s;
        mp[s]++;
    }
    for(auto [k,v]:mp)
    {
        if(v>total-v)
        {
            cout<<k<<'\n';
            return 0;
        }
    }
    cout<<"NONE\n";
    return 0;
}