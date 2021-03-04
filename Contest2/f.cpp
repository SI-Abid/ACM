#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
    string s;
    int t;
    set<string> st;
    cin>>t;
    for(int i=0; i<t; i++)
    {
        cin>>s;
        sort(s.begin(), s.end());
        s.erase(unique(s.begin(),s.end()),s.end());
        st.insert(s);
    }
 
    cout<<st.size()<<endl;
 
    return 0;
}