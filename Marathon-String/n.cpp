#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    vector<int> a;
    cin.ignore();
    for(int i=0;i<n+n;i++)
    {
        string s;
        getline(cin,s);
        int cn=0;
        for(auto c:s)
        {
            if(isalpha(c))
            {
                cn++;
            }
        }
        a.push_back(cn);
    }
    sort(a.begin(),a.end());
    bool flag=true;
    for(int i=0;i<n+n;i++)
    {
        if(a[i]+a[n+n-1-i]>m)
        {
            flag=false;
            break;
        }
    }
    if(flag)
    {
        cout<<"YES"<<endl;
    }
    else
    {
        cout<<"NO"<<endl;
    }
    return 0;
}