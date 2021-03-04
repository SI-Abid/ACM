#include<bits/stdc++.h>
#define ll long long int
#define pb push_back
using namespace std;
int main()
{
    int t, x=0;
    string s;
    cin>>t;
    while(t--)
    {
        cin>>s;
        (s[1]=='+')?x++:x--;
    }
    cout<<x<<endl;
    return 0;
}