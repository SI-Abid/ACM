#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int P = 10;
ll MOD = 1e9;
vector<ll> hashes;

ll getHash(string s)
{
    ll h = 0;
    for (int i = 0; i < s.size(); i++)
    {
        h = (h * P + (s[i] - '1' + 1)) % MOD;
    }
    return h;
}
ll getHash(ll prev_hash, char c)
{
    return (prev_hash * P + (c - '1' + 1)) % MOD;
}

ll binPow(ll a, ll b)
{
    ll res = 1;
    while (b)
    {
        if (b & 1)
        {
            res = res * a % MOD;
        }
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

ll subHash(int i, int j)
{
    if(i==0) return hashes[j];
    return (hashes[j] - hashes[i - 1] * binPow(10, j - i + 1) % MOD + MOD) % MOD;
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
    for (int i = 0; i < n; i++)
    {
        h = getHash(h, s[i]);
        hashes.push_back(h);
    }
    int j,k=n-1,mid;
    for (int i = 0; i < n / 2; i++)
    {
        j = i + 1;
        mid = (j + k) / 2;
        // if(mid-j+1>k-mid)
        // {
        //     mid--;
        // }
        ll a, b, c;
        while(j<=mid)
        {
            a = subHash(0, i);
            b = subHash(j, mid);
            c = subHash(mid+1, k);
            // cout<<a<<" "<<b<<" "<<(a+b)%MOD<<" "<<c<<endl;
            if((a+b)%MOD==c)
            {
                // cout << "YES" << endl;
                cout<<s.substr(0,j)<<"+"<<s.substr(j,mid-j+1)<<"="<<s.substr(mid+1,k-mid)<<endl;
                return 0;
            }
            else if((a+b)%MOD<c)
            {
                break;
            }
            mid--;
        }
    }
    // cout << "NO" << endl;
    return 0;
}