#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        int cnt[26];
        memset(cnt,0,sizeof(cnt));
        for(int i=0;i<n;i++)
        {
            char ch;
            cin>>ch;
            cnt[ch-'a']++;
        }
        int paircnt=0;
        int oddcnt=0;
        for(int i=0;i<26;i++)
        {
            paircnt+=(cnt[i]/2);
            oddcnt+=(cnt[i]%2);
        }
        int ans=2*(paircnt/k);
        oddcnt+=2*(paircnt%k);
        if(oddcnt>=k)
            ans++;
        cout<<ans<<endl;
    }
    return 0;
}