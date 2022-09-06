#include<bits/stdc++.h>
using namespace std;

vector<int> v;
// longest prefix suffix
void lps(string &s, int n)
{
    v.push_back(0);
    int i = 0, j = 1;
    while (j < n)
    {
        if (s[i] == s[j])
        {
            v.push_back(i + 1);
            i++;
            j++;
        }
        else if (i!= 0)
            i = v[i-1];
        else
        {
            v.push_back(0);
            j++;
        }
    }
}

int main()
{
    int t;
    cin>>t;
    for(int tc=1;tc<=t;tc++)
    {
        v.clear();
    
        string s,t;
        cin>>s;
        t=s;
        reverse(t.begin(),t.end());
        t+="_"+s;
        int n=t.length();
        lps(t,n);
        // cout<<v.back()<<'\n'<<s.size()<<'\n';
        int ans= 2*s.size();
        int last = v.back();
        printf("Case %d: %d\n",tc,ans-last);
    }
    return 0;
}