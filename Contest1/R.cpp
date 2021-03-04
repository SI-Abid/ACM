#include<bits/stdc++.h>
#define ll long long int
#define pb push_back
using namespace std;
int main()
{
    set<char> sc;
    string s;
    cin>>s;
    for(auto c:s)
    {
        sc.insert(c);
    }
    puts((sc.size()&1)?"IGNORE HIM!":"CHAT WITH HER!");
    return 0;
}