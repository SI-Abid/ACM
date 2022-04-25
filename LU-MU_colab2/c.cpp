#include<bits/stdc++.h>
using namespace std;

int dsum(int n)
{
    int sum=0;
    while(n>0)
    {
        sum+=n%10;
        n/=10;
    }
    return sum;
}

int main()
{
    int n,a,b;
    cin>>n>>a>>b;
    long long int sum=0;
    for(int i=1;i<=n;i++)
    {
        int dsum1=dsum(i);
        if(dsum1>=a && dsum1<=b)
        {
            sum+=i;
        }
    }
    cout<<sum<<endl;
    return 0;
}