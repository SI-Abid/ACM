#include "bits/stdc++.h"
using namespace std;

int main()
{
    int t;
    cin>>t;
    cin.ignore();
    for(int i=1; i<=t; i++)
    {
        cout<<"Case "<<i<<": ";
        
        string a, b;
        getline(cin, a);
        getline(cin, b);
        
        if(a==b)
        {
            puts("Yes");
        }
        else
        {
            // auto p = remove(a.begin(), a.end(), ' ');
            a.erase(remove(a.begin(), a.end(), ' '), a.end());
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