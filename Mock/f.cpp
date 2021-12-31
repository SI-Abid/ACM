#include <bits/stdc++.h>
using namespace std;

int min_window(string s, string t, vector<int> &m)
{
    int ans = INT_MAX;
    int count = t.size();

    int i = 0;
    int j = 0;

    while (j < s.length())
    {
        m[s[j]]--;
        if (m[s[j]] == 0)
            count--;

        if (count == 0)
        {
            while (count == 0)
            {
                if (ans > j - i + 1)
                {
                    ans = min(ans, j - i + 1);
                    // cout<<i<<" "<<j<<" "<<ans<<endl;
                }
                m[s[i]]++;
                if (m[s[i]] > 0)
                    count++;

                i++;
            }
        }
        j++;
    }

    if (ans != INT_MAX)
        return ans;
    else
        return 0;
}

int main()
{
    string s;
    cin >> s;
    vector<int> chars(256,0);
    string pat = "";
    for (int i = 0; i < s.size(); i++)
    {
        if (chars[s[i]] == 0)
        {
            chars[s[i]] = 1;
            pat += s[i];
        }
    }
    cout << min_window(s, pat, chars) << endl;
    return 0;
}