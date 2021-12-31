#include <bits/stdc++.h>
using namespace std;

int min_window(string s, string t)
{
    int m[256] = {0};

    int ans = INT_MAX;
    int start = 0;
    int count = 0;

    for (int i = 0; i < t.length(); i++)
    {
        if (m[t[i]] == 0)
            count++;
        m[t[i]]++;
    }

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
                    start = i;
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
    int chars[26] = {0};
    string pat = "";
    for (int i = 0; i < s.size(); i++)
    {
        if (chars[s[i] - 'a'] == 0)
        {
            chars[s[i] - 'a'] = 1;
            pat += s[i];
        }
    }
    cout << min_window(s, pat) << endl;
    return 0;
}