#include <bits/stdc++.h>

using namespace std;

int main()
{
    // freopen("in.txt", "r", stdin);
    string s;
    cin>>s;
    if(s.size()<3)
    {
        puts("No");
        return 0;
    }
    for(int i=0; i<s.size()-2; i++)
    {
        // if(s[i]=='.')
        //     continue;
        string sub=s.substr(i, 3);
        sort(sub.begin(), sub.end());
        // cout<<sub<<endl;
        if(sub=="ABC")
        {
            puts("Yes");
            return 0;
        }
    }
    puts("No");
    return 0;
}