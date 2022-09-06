#include<bits/stdc++.h>
using namespace std;

vector<long long> mem;
int base[] = {0,0,0,1,1,1,2,2,3,3};
long long dp(int n)
{
    if(n<=8)
        return mem[n] = base[n];
    if(mem[n]!=-1)
        return mem[n];
    return mem[n] = dp(n-2) + dp(n-3) + dp(n-4) - dp(n-5) - dp(n-6) - dp(n-7) + dp(n-9);
}
int main()
{
    int t;
    cin>>t;
    mem.resize(300019,-1);
    dp(300009);
    for(int tc=1;tc<=t;tc++)
    {
        // printf("Case %d: ",tc);
    
        int n;
        cin>>n;
        cout<<mem[n]<<'\n';
    }
    return 0;
}