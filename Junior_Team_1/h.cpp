#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(true)
    {
        SOSUR_BARI:
        if(t--==0)
            break;
        string s;
        cin>>s;
        for(int i =0; i<s.size()-1; i++)
        {
            if(s[i]+1==s[i+1] or (s[i]=='z' and s[i+1]=='a'));
            else
            {
                cout<<"NO"<<endl;
                goto SOSUR_BARI;
            }
        }
        cout<<"YES"<<endl;
    }
    return 0;
}