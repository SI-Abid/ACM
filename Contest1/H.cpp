#include "bits/stdc++.h"
#define ll long long
using namespace std;

int main()
{
    int t=1;
    string s;
    while(cin>>s && s!="*")
    {
        cout<<"Case "<<t++<<": ";
        if(s=="Hajj")
            puts("Hajj-e-Akbar");
        else 
            puts("Hajj-e-Asghar");
    }
    return 0;
}