#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        int n=s.size();
        int cnt=1;
        bool camel=true;
        for(int i=0;i<n;i++)
        {
            if(isupper(s[i]))
            {
                cnt++;
            }
        }
        puts( cnt <=7 ? "YES" : "NO");
    }
    return 0;
}