#include <bits/stdc++.h>

using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
#define ordered_set tree<pair<int, int>, null_type, greater<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>

#define ll long long
#define pb push_back
#define F first
#define S second
#define mk make_pair
#define pII pair<ll, ll>
#define all(v) v.begin(), v.end()
#define allr(v) v.rbegin(), v.rend()
#define Endl "\n"
#define boo bool ok = false
#define Case() cout << "Case " << ++cs << ": "
#define bug(a) cerr << #a << " : " << a << endl
#define Tc()      \
    ll T, cs = 0; \
    cin >> T;     \
    hell:         \
    while (T--)
#define Tanmoy                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0), cout.tie(0)

const ll Mod = 1e9 + 7, MAX = 2e6 + 10;
ll a[MAX], b[MAX], c[MAX], d[MAX], M[1005][1005], fact[200000];
const int p = 31, m = 1e9 + 7; /// for string hashing
vector<ll> ans;

long long compute_hash(string s)
{
    const int p = 31;
    const int m = 1e9 + 9;
    long long hash_value = 0;
    long long p_pow = 1;
    for (char c : s)
    {
        hash_value = (hash_value + (c - 'a' + 1) * p_pow) % m;
        p_pow = (p_pow * p) % m;
    }
    return hash_value;
}

int count_unique_substrings(string s, ll l, string tt)
{
    int n = s.size();
    int mm = tt.size();

    const int p = 31;
    const int m = 1e9 + 9;
    vector<long long> p_pow(n);
    p_pow[0] = 1;
    for (int i = 1; i < n; i++)
        p_pow[i] = (p_pow[i - 1] * p) % m;

    vector<long long> h(n + 1, 0);

    for (int i = 0; i < n; i++)
        h[i + 1] = (h[i] + (s[i] - 'a' + 1) * p_pow[i]) % m;

    int cnt = 0;
    set<long long> hs;
    for (int i = 0; i <= n - l; i++)
    {
        /*
                string pp = s.substr(i,l);
                vector<long long> hss((int)pp.size() + 1, 0);
                for (int i = 0; i < pp.size(); i++)
                    hss[i+1] = (hss[i] + (pp[i] - 'a' + 1) * p_pow[i]) % m;
        */
        long long cur_h = (h[i + l] + m - h[i]) % m;
        cur_h = (cur_h * p_pow[n - i - 1]) % m;
        cout << hss[pp.size()] << " " << cur_h << " " << h1[mm] << endl;
        if (cur_h == h1[mm])
        {
            cout << "YO" << endl;
            ans.push_back(i);
        }
    }
}

int main()
{

    Tanmoy;
    // freopen("in.txt", "r", stdin);

    ll n;
    cin >> n;
    // while(cin>>n){

    string txt, pat;
    cin >> pat >> txt;

    // ll x=compute_hash(pat);
    // bug(x);
    count_unique_substrings(txt, pat.size(), pat);

    for (auto it : ans)
        cout << it << "\n";
    ans.clear();

    // }

    return 0;
}
