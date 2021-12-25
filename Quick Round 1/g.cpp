#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s,t;
    cin>>s>>t;
    set<int> v;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]<=t[i])
        {
            v.insert(t[i]-s[i]);
        }
        else
        {
            v.insert(t[i]-s[i]+26);
        }
    }
    puts(v.size()!=1?"No":"Yes");
    
    return 0;
}