#include<bits/stdc++.h>
using namespace std;

void kmp(string &s, vector<int> &failure)
{
    int i = 0;
    int j = 1;
    failure.push_back(0);
    while(s[j])
    {
        if(s[i]==s[j])
        {
            failure.push_back(i+1);
            i++;
            j++;
        }
        else
        {
            if(i!=0)
            {
                i = failure[i-1];
            }
            else
            {
                failure.push_back(0);
                j++;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    int tc=1;
    cin>>t;
    while(t--)
    {
        cout<<"Case "<<tc++<<": ";
        string s;
        cin>>s;
        string tmp = s;
        reverse(s.begin(),s.end());
        s+="$"+tmp;
        
        vector<int> fail;
        kmp(s,fail);

        int ans= (2*tmp.size()) - fail.back();
        cout << ans << '\n';

    }   
    return 0;
}