#include<bits/stdc++.h>
using namespace std;

int failure[100000];

void build(string pat, int size)
{
    failure[0]=0;

    for(int i=1; i<size; i++)
    {
        int j=failure[i-1];
        while (true)
        {
            if(pat[j]==pat[i])
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

int main()
{
    string s;
    cin>>s;
    int n=s.size();
    build(s,n);
    int cnt=0;

    for (int i = 0; i <= n; i++)
    {
        cout<<i<<" "<<failure[i]*2<<endl;
        if(failure[i])
            cnt++;
    }
    
    cout<<cnt<<endl;
    return 0;
}