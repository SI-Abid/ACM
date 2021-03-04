#include "bits/stdc++.h"
using namespace std;

int main()
{
    // freopen("in.txt", "r", stdin);
    int n;
    string s;
    cin>>n>>s;
    int cnt=0;
    for(auto c:s)
    {
        if(c=='0')
            cnt++;
        else 
            cnt--;
    }
    if(cnt)
    {
        puts("1");
        cout<<s<<endl;
    }
    else
    {
        puts("2");
        cout<<s[0]<<" "<<s.substr(1, n-1)<<endl;
    }
    return 0;
}