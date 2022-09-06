#include<bits/stdc++.h>
using namespace std;

int dp[1002][1002];

int solve(string &s, int i, int j)
{
    if(i >= j)
        return 0;
    if(dp[i][j] != -1)
        return dp[i][j];

    int ans = 0;
    if(s[i] == s[j])
        ans = solve(s, i + 1, j - 1);
    else
        ans = 1 + min(solve(s, i + 1, j), solve(s, i, j - 1));
    return dp[i][j] = ans;
}

int main()
{
    int t;
    cin>>t;
    for(int tc=1;tc<=t;tc++)
    {
        printf("Case %d: ",tc);
    
        string s;
        cin>>s;
        int n=s.size();
        int i=0,j=n-1;
        memset(dp,-1,sizeof(dp));
        int ans=solve(s,i,j);
        cout<<ans<<'\n';
    }
    return 0;
}