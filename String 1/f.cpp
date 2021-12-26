// knuth morris pratt
#include<bits/stdc++.h>
using namespace std;

int failure[100000];
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

int kmp(string text, string pat)
{
    int n, m;
    n=text.size();
    m=pat.size();
    build(pat, m);

    int i, j,cnt;
    i=j=cnt=0;

    while(true)
    {
        if(j==n)
        {
            return cnt;
        }
        if(text[j]==pat[i])
        {
            i++;
            j++;
            if(i==m)
            {
                i=0;
                cnt++;
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
    return cnt;
}

int main()
{
    int n,t;
    cin>>n>>t;
    string s="";
    for(int i=0;i<n;i++)
    {
        string ss;cin>>ss;
        s+=ss+"#";
    }
    for(int i=0;i<t;i++)
    {

    }
    return 0;
}