#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

// vector<long long> power(1002);

// void precompute()
// {
//     power[0] = 1;
//     for(int i = 1; i < 1002; i++)
//         power[i] = (power[i - 1] * p) % mod;
// }

int getHash(string s, int p)
{
    int ans = 0;
    for(int i = 0; i < s.size(); i++)
        ans = (ans * p + s[i]) % mod;
    return ans;
}

int main()
{
    int n,i,h1,h2;
    string s;
    cin >> n;
    // precompute();
    vector<int> hash1, hash2;
    for(i = 0; i < n; i++)
    {
        cin >> s;
        hash1.push_back(getHash(s, 127));
        hash2.push_back(getHash(s, 131));
    }
    sort(hash1.begin(), hash1.end());
    sort(hash2.begin(), hash2.end());
    cin>>n;
    for(i = 0; i < n; i++)
    {
        cin >> s;
        h1 = getHash(s, 127);
        h2 = getHash(s, 131);
        // check if h is present in list
        bool flag = binary_search(hash1.begin(), hash1.end(), h1);
        flag &= binary_search(hash2.begin(), hash2.end(), h2);
        if(flag)
            cout << "yes\n";
        else
            cout << "no\n";
    }
    return 0;
}