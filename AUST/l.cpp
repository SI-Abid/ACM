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
        bool ok = true;
        while(n--)
        {
            int x;cin>>x>>x;
            if(x%6!=0)
            {
                ok = false;
                // break;
            }
        }
        cout<<"Case "<<tc++<<": ";
        if(ok)
        {
            cout<<"The number is both square and cube.\n";
        }
        else
        {
            cout<<"The number does not meet expectation.\n";
        }
        // if()
    }
    return 0;
}