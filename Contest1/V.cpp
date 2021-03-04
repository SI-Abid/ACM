#include "bits/stdc++.h"
#define uint unsigned int
#define ll unsigned long long
using namespace std;
int main ()
{
    // freopen("in.txt","r",stdin);
	int n, k;
    string s;
    cin>>n>>k>>s;
    char vc[k];
    for(auto &c:vc)
        cin>>c;

    vector<int> sublen;
    int len=0;
    bool match;
    for(int i=0; ;i++)
    {
        match=false;
        for(auto c:vc)
        {
            if(s[i]==c)
            {
                len++;
                match=true;
            }
        }
        if(!match)
        {
            sublen.push_back(len);
            len=0;
        }
        if(s[i]=='\0')
            break;
    }
    ll ans=0;
    for(ll z:sublen)
    {
        ans+=(z*(z+1)/2);
    }
    cout<<ans<<endl;
	return 0;
}