#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;
    bool flag = false;
    for(int i = 0; i < s.size()-1; i++)
        if(s[i]==s[i+1])
            flag = true;
    
    puts(flag ? "Bad" : "Good");
    return 0;
}