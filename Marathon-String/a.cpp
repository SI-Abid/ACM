#include<bits/stdc++.h>
using namespace std;

int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    int t;
    cin>>t;
    for(int tc=1;tc<=t;tc++)
    {
        printf("Case %d: ",tc);
    
        string s;
        cin>>s;
        if(s[4]=='s')
            cout<<s<<'\n';
        else
            cout<<s.substr(0,4)<<'s'<<s.substr(4)<<'\n';
    
    }
    return 0;
}