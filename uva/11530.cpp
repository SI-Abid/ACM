#include "bits/stdc++.h"
using namespace std;

int main()
{
    int t;
    cin>>t;
    cin.ignore();
    for(int i=1; i<=t;i++)
    {
        string s;
        int arr[]={1,2,3,1,2,3,1,2,3,1,2,3,1,2,3,1,2,3,4,1,2,3,1,2,3,4};
        int ans=0;
        getline(cin, s);
        cout<<"Case #"<<i<<": ";
        for(auto c:s)
        {
            if(c==' ')
                ans++;
            else 
            {
                int x=c-97;
                ans+=(arr[x]);
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}