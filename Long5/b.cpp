#include <bits/stdc++.h>
using namespace std;

const int mx = 10000000;
bool ip[mx];

void prime()
{
    memset(ip, true, mx);
    
    for(int i=2; i*i<=mx; i++)
    {
        if(ip[i])
        {
            for(int j=2*i; j<=mx; j+=i)
            {
                ip[j]=false;
            }
        }
    }
}

int rev(int num)
{
    int val=0;
    while(num)
    {
        val*=10;
        val+=num%10;
        num/=10;
    }
    return val;
}

int main(int argc, char* argv[])
{
    if(argc == 2 or argc == 3) freopen(argv[1], "r", stdin);
    if(argc == 3) freopen(argv[2], "w", stdout);
    ios::sync_with_stdio(false);

    prime();

    int n;
    while(cin>>n)
    {
        cout<<n;
        if(ip[rev(n)])
        {
            cout<<" is emirp.";
        }
        else if(ip[n])
        {
            cout<<" is prime.";
        }
        else
        {
            cout<<" is not prime.";
        }
        cout<<endl;
    }   
    
    return 0;
}
