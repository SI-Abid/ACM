#include<bits/stdc++.h>
using namespace std;

int main()
{
    int a,b,c;
    cin>>a>>b>>c;
    for(int i=a;i<=1000000;i+=a)
    {
        if(i%b==c)
        {
            puts("YES");
            return 0;
        }
    }
    puts("NO");
    return 0;
}