#include "bits/stdc++.h"
using namespace std;

int main()
{
    int t;
    cin>>t;
    for(int i=1; i<=t; i++)
    {
        cout<<"Case "<<i<<": ";
        
        string a, b;
        getline(cin, a);
        getline(cin,b);
        
        if(a==b)
        {
            puts("Yes");
        }
        else
        {
            auto p = remove(a.begin(), a.end(), ' ');
            a.erase(p, a.end());
            if(a==b)
            {
                puts("Output Format Error");
            }
            else
            {
                puts("Wrong Answer");
            }
            
        }
        
    }
    return 0;
}