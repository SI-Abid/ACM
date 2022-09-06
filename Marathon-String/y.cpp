#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
int P = 10;
ll MOD = 1e15;
vector<ll> hashes;

ll getHash(string s) 
{
    ll h = 0;
    for (int i = 0; i < s.size(); i++) {
        h = (h * P + (s[i]-'1'+1)) % MOD;
    }
    return h;
}
ll getHash(ll prev_hash, char c)
{
    return (prev_hash * P + (c-'1'+1)) % MOD;
}
ll subHash(int i, int j)
{
    ll h = hashes[j];
    if (i > 0) {
        h = (h - hashes[i-1] * (ll)pow(P, j-i+1)) % MOD;
        if (h < 0) h += MOD;
    }
    return h;
}

ll pow(ll a, ll b)
{
    ll res = 1;
    while (b) {
        if (b & 1) {
            res = res * a % MOD;
        }
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

int main()
{
    // s = 12345168
    // using hash check if 12345168 can be divided into 3 parts
    // such that a+b = c
    string s;
    cin >> s;
    int n = s.size();
    ll h = 0;
    // hashes.push_back(h);
    for (int i = 0; i < n; i++) {
        h = getHash(h, s[i]);
        hashes.push_back(h);
    }
    // divide into 3 parts and check if a+b = c
    for (int i = 0; i < n-1; i++) {
        for (int j = i+1; j < n-1; j++) {
            ll a = subHash(0, i);
            ll b = subHash(i+1, j);
            ll c = subHash(j+1, n-1);
            if (a + b == c) {
                cout << "YES" << endl;
                return 0;
            }
        }
    }
    cout << "NO" << endl;
    return 0;
}