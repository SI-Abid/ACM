#include<bits/stdc++.h>
using namespace std;

int main()
{
    map<string,int> m;
    int t; cin>>t;
    while(t--)
    {
        int q; cin>>q;
        string s; cin>>s;
        if(q==1)
        {
            int x; cin>>x;
            m[s]+=x;
        }
        else if(q==2)
        {
            m.erase(s);
        }
        else
        {
            cout<<m[s]<<endl;
        }
    }   
    
    return 0;
}