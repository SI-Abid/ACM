#include<bits/stdc++.h>
using namespace std;

int failure[1000];
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
    // ios_base::sync_with_stdio(false);
    // cin.tie(0);
    int t;
    cin>>t;
    cin.ignore();
    for(int tc=1;tc<=t;tc++)
    {
        printf("Case %d: ",tc);
    
        string a,b;
        getline(cin,a);
        // cin.ignore();
        getline(cin,b);
        //remove all spaces from a and b
        a.erase(remove(a.begin(),a.end(),' '),a.end());
        b.erase(remove(b.begin(),b.end(),' '),b.end());
        // convert to lowercase
        transform(a.begin(),a.end(),a.begin(),::tolower);
        transform(b.begin(),b.end(),b.begin(),::tolower);
        // sort the strings
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        // cout<<"==========\n"<<a<<"\n"<<b<<endl;
        if(a==b)
        {
            cout<<"Yes\n";
        }
        else
        {
            cout<<"No\n";
        }
    }
    return 0;
}