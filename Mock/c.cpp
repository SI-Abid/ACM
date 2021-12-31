#include<bits/stdc++.h>
using namespace std;

int prime[1005];
void build()
{
    prime[0]=prime[1]=1;
    for(int i=2;i*i<=1000;i++)
    {
        if(prime[i]==0)
        {
            for(int j=i*i;j<=1000;j+=i)
            {
                prime[j]=1;
            }
        }
    }
}
int main()
{
    build();
    int t;cin>>t;
    while(t--)
    {
        long long n;
        cin>>n;
        int p=0;
        while(n>0)
        {
            p+=(n&1);
            n>>=1;
        }
        if(!prime[p])
            cout<<" Binary prime"<<endl;
        else
            cout<<"-1"<<endl;
    }
    return 0;
}