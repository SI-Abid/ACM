#include "bits/stdc++.h"
using namespace std;

int main()
{
    int tc;
    string s, t;
    cin>>tc;
    cin.ignore();
    while(tc--)
    {
        int cnt=0;
        getline(cin, s);
        istringstream token(s);
        token>>t;
        while(token)
        {
            cnt++;
            token>>t;
        }
        cout<<cnt<<endl;
    }
    return 0;
}