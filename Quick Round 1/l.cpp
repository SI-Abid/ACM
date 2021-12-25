#include<bits/stdc++.h>
using namespace std;

int main()
{
    int cnt=0;
    char c;
    while(cin>>c)
    {
        c=='+'?cnt++:cnt--;
    }
    cout<<cnt<<endl;
    return 0;
}