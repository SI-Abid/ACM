#include <bits/stdc++.h>

using namespace std;

bool isvowel(char c)
{
    return (c=='a' || c=='e' || c=='i' || c=='o' || c=='u');
}

int main()
{
    freopen("in.txt", "r", stdin);
    string a, b, c;
    getline(cin, a);
    getline(cin, b);
    getline(cin, c);
    int an=0, bn=0, cn=0;
    for(auto ch:a)
    {
        if(isvowel(ch))
            an++;
    }
    for(auto ch:b)
    {
        if(isvowel(ch))
            bn++;
    }
    for(auto ch:c)
    {
        if(isvowel(ch))
            cn++;
    }
    puts((an==5 && bn==7 && cn==5)?"YES":"NO");
    return 0;
}