#include <bits/stdc++.h>

using namespace std;

bool isvowel(char c)
{
    return (c=='a' || c=='e' || c=='i' || c=='o' || c=='u');
}

int main()
{
    freopen("in.txt", "r", stdin);
    int t;
    for(cin>>t;t;t--)
    {
        string s;
        bool arr[26]={false};
        cin>>s;
        // reverse(s.begin(), s.end());
        if(s.size()==1)
        {
            cout<<s<<endl;
            continue;
        }
        for (int i = 0; i < s.size(); i++) 
        {
            int j = i;
            while (j + 1 < s.size() && s[j + 1] == s[i])
                j++;
            if ((j - i) % 2 == 0)
                arr[s[i] - 'a'] = true;
            i = j;
	    }
        
        for(int i=0; i<26; i++)
        {
            if(arr[i])
                cout<<(char)('a'+i);
        }

        puts("");
    }
    return 0;
}