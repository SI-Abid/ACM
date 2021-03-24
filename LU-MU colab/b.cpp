#include "bits/stdc++.h"
using namespace std;

int main()
{
    int l;
    string s;
    cin>>l>>s;
    bool ok=true;
    for(int i=0; i<l-1; i++)
    {
        if(s[i]>s[i+1])
        {
            ok=false;
            break;
        }
    }
    if(ok)
    {
        cout<<"Yes"<<endl;
    }
    else
    {
        cout<<"No"<<endl;
    }
    return 0;
}