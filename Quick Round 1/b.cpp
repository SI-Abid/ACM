#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin>>s;
    string t="oxxoxxoxxoxxoxxoxxoxxoxxoxxoxxoxxoxxoxxoxxoxxoxx";
    for(int i=0;i<t.size()-s.size();i++)
    {
        if(s==t.substr(i,s.size()))
        {
            puts("Yes");
            return 0;
        }
    }
    puts("No");
    return 0;
}