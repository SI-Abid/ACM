#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int cnt=0;
    while(n--)
    {
        int x;
        cin>>x;
        while(x%2==0)
        {
            x/=2;
            cnt++;
        }
    }
    cout<<cnt<<endl;
    return 0;
}