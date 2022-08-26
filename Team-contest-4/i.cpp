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
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll a, b, n;
    cin >> a >> b >> n;

    ll ans = ((((a + 1) * (b + 1)) / (n + 1)) - 1);

    cout << ans << endl;

    return 0;
}
