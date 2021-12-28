#include<bits/stdc++.h>
using namespace std;

int failure[100000];

void build(string pat, int size)
{
    failure[0]=0;

    for(int i=1; i<size; i++)
    {
        int j=failure[i-1];
        while (j>0 && pat[i]!=pat[j])
            j=failure[j-1];
        if(pat[i]==pat[j])
            j++;
        failure[i]=j;
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
        cout<<i<<" "<<failure[i]<<endl;
        if(failure[i])
            cnt++;
    }
    
    cout<<cnt<<endl;
    return 0;
}