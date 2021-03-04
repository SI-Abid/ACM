#include <bits/stdc++.h>

using namespace std;


int main()
{
    int n;
    string s;
    cin>>n>>s;
    int ans=0;
    for(int i=0; i<s.size()-2; i++)
    {
        if(s[i]=='x' && s[i+1]=='x' && s[i+2]=='x')
            ans++;
    }
    // if(ans==-1)
    //     puts("0");
    // else
        cout<<ans<<endl;
    return 0;
}