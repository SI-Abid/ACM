#include "bits/stdc++.h"
using namespace std;

int main()
{
    // freopen("in.txt","r",stdin);
    string s;
    while(cin>>s)
    {
        for(char c:s)
        {
            printf("%c", c-7);
        }
        puts("");
    }
    return 0;
}