#include<bits/stdc++.h>
using namespace std;

// add two very large numbers
string sum(string a, string b)
{
    string ans="";
    int carry = 0;
    int i = a.size() - 1, j = b.size() - 1;
    while (i >= 0 || j >= 0)
    {
        int x = (i >= 0 ? a[i] - '0' : 0);
        int y = (j >= 0 ? b[j] - '0' : 0);
        int sum = x + y + carry;
        carry = sum / 10;
        ans.push_back(sum % 10 + '0');
        i--;
        j--;
    }
    if (carry)
        ans.push_back(carry + '0');
    reverse(ans.begin(), ans.end());
    return ans;
}

int main()
{
    int t;
    cin>>t;
    for(int tc=1;tc<=t;tc++)
    {
        string a,b;
        cin>>a>>b;
        string ans=sum(a,b);
        printf("Case #%d: ",tc);
        cout<< ans<<'\n';
    
    }
    return 0;
}