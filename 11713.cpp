#include "bits/stdc++.h"
#define checkvowel(c) (c=='a' || c=='e' || c=='i' || c=='o' || c=='u')
using namespace std;

int main()
{
    int t;
    cin>>t;
    // cin.ignore();
    for(int i=1; i<=t;i++)
    {
        string a, b;
        cin>>a>>b;
        if(a.size() != b.size())
        {
            puts("No");
            continue;
        }
        bool check=true;
        for(int i=0; i<a.size() && check;i++)
        {
            if(a[i]!=b[i])
            {
                if(checkvowel(a[i]) && checkvowel(b[i]))
                {
                    check=true;
                }
                else
                {
                    check=false;
                }
            }
        }
        puts(check?"Yes":"No");
    }
    return 0;
}