#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin>>s;
    int n = s.size();
    stack<char> st;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='(')
        {
            st.push(s[i]);
        }
        else if(s[i]==')')
        {
            if(st.empty())
            {
                cout<<"No"<<endl;
                return 0;
            }
            else
            {
                if(st.top()=='(')
                    st.pop();
                else
                {
                    cout<<"No"<<endl;
                    return 0;
                }
            }
        }
    }
    if(st.empty())
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;
    return 0;
}