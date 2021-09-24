#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s[3];
    for (int i = 0; i < 3; i++)
    {
        cin>>s[i];
    }
    string t;
    cin>>t;
    for (int i = 0; i < t.size(); i++)
    {
        cout<<s[t[i]-49];
    }
    cout<<endl;
    
    return 0;
}