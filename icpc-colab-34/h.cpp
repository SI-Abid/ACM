#include<bits/stdc++.h>
using namespace std;

int failure[1000000];
void build(string pat, int size)
{
    failure[0]=failure[1]=0;

    for(int i=2; i<=size; i++)
    {
        int j=failure[i-1];
        while (true)
        {
            if(pat[j]==pat[i-1])
            {
                failure[i]=j+1;
                break;        
            }
            if(j==0)
            {
                failure[i]=0;
                break;
            }
            j=failure[j];
        }
    }
}

pair<int,int> kmp(string text, string pat, int k)
{
    int n, m;
    n=text.size();
    m=pat.size();
    build(pat, m);

    int i, j, count=0;
    i=j=0;

    while(true)
    {
        if(j==n)
        {
            return {count, j};
        }
        if(text[j]==pat[i])
        {
            i++;
            j++;
            if(i==m)
            {
                count++;
                if(count==k)
                    return {count, j-i+1};
                i=failure[i];
            }
        }
        else
        {
            if(i==0)
                j++;
            else
                i=failure[i];
        }
    }
    return {count, j};
}

int main()
{
    string text, pat;
    cin>>text;
    int t;
    cin>>t;
    for(int tc=1;tc<=t;tc++)
    {
        // printf("Case %d: ",tc);
        int k;
        cin>>pat>>k;
        pair<int,int> ans=kmp(text, pat, k);
        if(ans.first==k)
            cout<<ans.second<<endl;
        else
            cout<<"-1"<<endl;
    }
    return 0;
}
