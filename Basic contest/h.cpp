#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t,tc=1;
    cin>>t;
    while(t--)
    {
        cout<<"Case "<<tc++<<": ";
        int n,m,k;
        cin>>n>>m>>k;
        vector<int> a;
        for (int i = 0; i < n; i++)
        {
            if(i<3)
            {
                a.push_back(i+1);
            }
            else
            {
                a.push_back((a[i-1]+a[i-2]+a[i-3])%m);
            }
        }
        
    }
    return 0;
}