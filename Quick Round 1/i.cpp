#include<bits/stdc++.h>
using namespace std;

int main()
{
    int a,b;
    cin>>a>>b;
    if(max(a,b)>8)
        cout<<":("<<endl;
    else
        cout<<"Yay!"<<endl;
    return 0;
}