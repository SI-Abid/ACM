#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    int t;
    cin>>t;
    // vector<long long> v;
    // v.push_back(1);
    // for(int i=2;i<=1000000000;i++)
    // {
    //     v.push_back(v[i-1]+i);
    // }
    while(t--)
    {
        ll n;
        cin>>n;
        ll root = ceil(sqrt(8*n+1));
        ll ans = root/2;
        ll dif = ans*(ans+1)/2-n;
        cout<< 1+dif<<" "<<ans-dif<<endl;
    }
    return 0;
}