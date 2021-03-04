#include <bits/stdc++.h>

using namespace std;

bool palindrom(string s)
{
    string p = s; 
    reverse(s.begin(), s.end());
    if(s==p)
        return true;
    return false;
}

int main()
{
    // freopen("in.txt", "r", stdin);
    string s;
    cin>>s;
    int n=s.size();
    if(palindrom(s))
    {
        for(int i=n-1; i>=2; i--)
        {
            for(int j=0; j<=n-i; j++)
            {
                string sub=s.substr(j, i);
                if(!palindrom(sub))
                {
                    cout<<i<<endl;
                    return 0;
                }
            }
        }
        puts("0");
    }
    else
    {
        cout<<n<<endl;
    }
    return 0;
}