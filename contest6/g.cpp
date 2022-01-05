#include<iostream>
using namespace std;
int main()
{
    string s;
    int i,j;
    cin>>s;
    for(int k=0;k<s.size();k++)
    {
        if(s[k]=='A')
        {
            i=k;
            break;
        }
    }
    for(int k=s.size()-1;k>=0;k--)
    {
        if(s[k]=='Z')
        {
            j=k;
            break;
        }
    }
    cout<<j-i+1<<endl;
}
