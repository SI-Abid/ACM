#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t,tc=1;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int> a(n);
        for(int i=0;i<n;i++)
            cin>>a[i];
        stack<int> st;
        vector<int> left(n),right(n);
        for(int i=0;i<n;i++)
        {
            while(!st.empty())
            {
                if(a[st.top()]>=a[i])
                {
                    st.pop();
                }
                else
                {
                    break;
                }
            }
            if(st.empty())
            {
                left[i]=0;
            }
            else
            {
                left[i]=st.top()+1;
            }
            st.push(i);
        }
        while(st.size())
            st.pop();
        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty())
            {
                if(a[st.top()]>=a[i])
                {
                    st.pop();
                }
                else
                {
                    break;
                }
            }
            if(st.empty())
            {
                right[i]=n-1;
            }
            else
            {
                right[i]=st.top()-1;
            }
            st.push(i);
        }
        int ans=0;
        for(int i=0;i<n;i++)
        {
            ans=max(ans,(right[i]-left[i]+1)*a[i]);
        }
        cout<<"Case "<<tc++<<": "<<ans<<endl;
    }    
    return 0;
}