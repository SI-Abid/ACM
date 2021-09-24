#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    
    if(n<40)   
    {
        cout<<40-n;
    }
    else if(n<70)
    {
        cout<<70-n;
    }
    else if (n<90)
    {
        cout<<90-n;
    }
    else
    {
        cout<<"expert";
    }
    cout<<endl;
    
    return 0;
}