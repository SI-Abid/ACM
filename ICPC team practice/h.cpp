#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    for(int tc=1;tc<=t;tc++)
    {
        // printf("Case %d: ",tc);
    
        string s;
        cin>>s;
        map<char,int> m;
        for(int i=0;i<s.size();i++)
        {
            m[s[i]]=i;
        }
        int xi=-1,xj=-1;
        bool found=false;
        for (int i = 0; i < s.size() and !found; i++)
        {
            if(m.begin()->first==s[i])
            {
                continue;
            }
            // if(m[s[i]]==i)
            // {
            //     continue;
            // }
            for(auto it=m.begin(); it!=m.end();it++)
            {
                if(it->first<=s[i] and it->second>i)
                {
                    xi=i;
                    xj=it->second;
                    found=true;
                    break;
                }
            }
        }
        // cout<<xi<<' '<<xj<<endl;
        // if(xj==-1)
        //     reverse(s.begin()+xi,s.end());
        // else
        if(xi!=-1 and xj!=-1)
            reverse(s.begin()+xi,s.begin()+xj+1);
        cout<<s<<'\n';
    }
    return 0;
}