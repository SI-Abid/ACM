// knuth moris pratt algorithm
#include<bits/stdc++.h>
using namespace std;


int main()
{
    string text="";
    for(int i=0; i<100; i++)
    {
        text+="oxx";
    }
    string pat;
    cin>>pat;
    puts(kmp(text,pat)?"Yes":"No");
    return 0;
}