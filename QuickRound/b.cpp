#include<bits/stdc++.h>
using namespace std;

int main()
{
    string a,b,c;
    cin>>a>>b>>c;
    if(a.back()==b.front() and b.back()==c.front())
        puts("YES");
    else
        puts("NO");
    return 0;
}