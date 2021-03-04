#include "bits/stdc++.h"
using namespace std;

int main()
{
    int t;
    cin>>t;
    for(int i=1; i<=t;i++)
    {
        cout<<"Case "<<i<<": ";
        string a, b="";
        char c;
        cin>>a;
        int j=0;
        while(j<a.size())
        {
            string num = "";
            c=a[j++];
            while(isdigit(a[j]))
            {
                num+=(a[j++]);
            }
            int n=stoi(num);
            while(n--)
            {
                b+=c;
            }
        }
        cout<<b<<endl;
    }
    return 0;
}