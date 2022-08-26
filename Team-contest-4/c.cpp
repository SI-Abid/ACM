#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define MX 1000005
#define mod 1000000007
#define ll long long
#define pb push_back
#define pll pair<ll, ll>
#define endl "\n"
#define bug(a) cerr << #a << " : " << a << endl
#define all(x) (x).begin(), (x).end()
#define allr(x) (x).rbegin(), (x).rend()

int main()
{

    ll n;
    cin >> n;
    vector<ll> v;
    for (int i = 1; i <= n; i++)
    {
        string s;
        cin >> s;
        if (s[0] == '-' || s.size() > 8)
            continue;
        ll x = stoll(s);
        v.pb(x);
    }

    sort(all(v));

    ll ans = v.size();
    for (int i = 0; i < v.size(); i++)
    {
        if (i != v[i])
        {
            ans = i;
            break;
        }
    }

    cout << ans << endl;

    return 0;
}
