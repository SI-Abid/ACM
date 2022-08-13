#include<bits/stdc++.h>
using namespace std;

int main()
{
    int l,w;
    cin>>l>>w;
    if(w<l or w>l*26)
    {
        cout<<"impossible\n";
        return 0;
    }
    int x;
    for(int i=0;i<l;i++)
    {
        x=min(26,w-l+i+1);
        w-=x;
        cout<<(char)('a'+x-1);
    }
    
    // l--;
    // cout<<(char)('a'+(w-(l*x)-1);
    
    cout<<"\n";
    return 0;
}