#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    for(int tc=1;tc<=t;tc++)
    {
        // printf("Case %d: ",tc);
    
        string s,t;
        int n;
        cin>>s>>n>>t;
        int cnt=0;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='?')
                cnt++;
        }
        sort(t.rbegin(),t.rend());
        for(auto x:s)
        {
            if(x=='?')
            {
                cout<<t.back();
                t.pop_back();
                cnt--;
                if(cnt==0 and t.size())
                {
                    for(auto xx=t.rbegin();xx!=t.rend();xx++)
                    {
                        cout<<*xx;
                    }
                }
            }
            else
            {
                cout<<x;
            }
        }
        cout<<'\n';
    }
    return 0;
}