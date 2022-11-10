#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

// using kmp to find the subsequences

bool kmp(string s, string t)
{
    int n = s.size();
    int m = t.size();
    vector<int> lps(m, 0);
    int i = 1, j = 0;
    while (i < m)
    {
        if (t[i] == t[j])
        {
            lps[i] = j + 1;
            i++;
            j++;
        }
        else
        {
            if (j == 0)
            {
                lps[i] = 0;
                i++;
            }
            else
            {
                j = lps[j - 1];
            }
        }
    }
    i = 0, j = 0;
    while (i < n)
    {
        if (s[i] == t[j])
        {
            i++;
            j++;
        }
        else
        {
            if (j == 0)
            {
                i++;
            }
            else
            {
                j = lps[j - 1];
            }
        }
        if (j == m)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    cin>>n;
    while(n--)
    {
        string t;
        cin >> t;
        // build_failure(t);
        if (kmp(s, t))
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }
    return 0;
}