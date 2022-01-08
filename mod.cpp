#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define check freopen("in.txt", "r", stdin)
#define biggo ios_base::sync_with_stdio(false);cin.tie(0),cout.tie(0)
#define MOD 1000000007

int gcd(ll a,ll b)
{
    if(b==0)return a;
    else return gcd(b,a%b);
}

ll BigMod(ll r, ll pro)
{
    cout<<"base "<<r<<" power "<<pro<<endl;
    if(pro==0)return 1;
    if(pro&1)
        return r*BigMod((r*r)%MOD,pro/2)%MOD;
    else
        return BigMod((r*r)%MOD,pro/2)%MOD;
}

int main()
{
    BigMod(2,263);
    // ll n;
    // cin>>n;
    // ll k = 1;
    // ll arr[n];
    // for(int i=0;i<n;i++)
    // {
    //     cin>>arr[i];
    // }
    // ll pro=1,g,r = arr[0];
    // for(int i=0;i<n;i++)
    // {
    //     pro = ((pro%MOD)*(arr[i]%MOD))%MOD;
    //     r = gcd(r,arr[i]);
    //     r = r%MOD;
    // }
    // cout<<BigMod(r,pro,MOD)<<endl;
}
/*
                2^255
                /   \
            2^1   (2^2)^127
                  /    \
                2^1   (4^2)^63
                        /    \
                        2^1  (16^2)^31
                                /    \
                            2^1   (256^2)^15
                                    /    \
                                2^1   (65536^2)^7
                                        /    \
                                    2^1   (4294967296^2)^3
                                            /    \
                                        2^1   (967....^2)^1
                                                /
                                              2^0
*/