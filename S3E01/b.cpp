#include<bits/stdc++.h>
using namespace std;

int main()
{
    float x;
    cin>>x;
    int y = (int)(x*10)%10;
    cout<<(int)x;
    if(y>=0 and y<=2)
    {
        puts("-");
    }else if(y>=3 and y<=6)
    {
        puts("");
    }else if(y>=7 and y<=9)
    {
        puts("+");
    }
    
    return 0;
}