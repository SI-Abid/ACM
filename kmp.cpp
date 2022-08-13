// knuth moris pratt algorithm
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

bool kmp(string text, string pat)
{
    int n, m;
    n=text.size();
    m=pat.size();
    build(pat, m);

    int i, j;
    i=j=0;

    while(true)
    {
        if(j==n)
        {
            return false;
        }
        if(text[j]==pat[i])
        {
            i++;
            j++;
            if(i==m)
                return true;
        }
        else
        {
            if(i==0)
                j++;
            else
                i=failure[i];
        }
    }
    return false;
}

int main()
{
    string text="";
    for(int i=0; i<100; i++)
    {
        text+="oxx";
    }
    string pat;
    cin>>pat;
    puts(kmp(text,pat)?"Yes":"No");
    return 0;
}