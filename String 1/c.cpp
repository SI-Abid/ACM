#include<bits/stdc++.h>
using namespace std;

#define ll long long

ll hash_2d[1001][1001];
ll hash_pat[101][101];
ll p=31;
ll mod = 1e9 + 7;
ll inverse_p[1001];

ll sub_hash(ll hashi, ll hashj, ll pi)
{

}

int mmi

void solve()
{
    ll pp;
    int n,m,x,y;

    cin>>n>>m;
    vector<string> s(n);
    for(int i=0;i<n;i++)
        cin>>s[i];

    cin>>x>>y;
    vector<string> pat(x);
    for(int i=0;i<x;i++)
        cin>>pat[i];

    for(int i=0;i<n;i++)
    {
        inverse_p[i]=mmi(p,i+1);
    }

    ll ans=0;
    for(int i=0;i<n;i++)
    {
        pp=1;
        for(int j=0;j<m;j++)
        {
            hash_2d[i+1][j+1]=(hash_2d[i][j]+(s[i][j]-96)*pp)%mod;
            pp*=p;
        }
    }
    for(int i=0;i<x;i++)
    {
        pp=1;
        for(int j=0;j<y;j++)
        {
            hash_pat[i+1][j+1]=(hash_pat[i][j]+(pat[i][j]-96)*pp)%mod;
            pp*=p;
        }
    }
    // match for sub hash
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}