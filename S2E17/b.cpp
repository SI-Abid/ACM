#include "bits/stdc++.h"
using namespace std;

#define ll long long
#define ull unsigned long long
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define be begin()
#define en end()
#define all(x) (x).begin(),(x).end()
#define out cout<<setprecision(20)

typedef vector<int> vi;
typedef vector<ll> vll;
typedef set<int> si;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MOD = 1e9 + 7;
const int INF = 1e9;

int main(int argc, char* argv[])
{
    if(argc == 2 or argc == 3) freopen(argv[1], "r", stdin);
    if(argc == 3) freopen(argv[2], "w", stdout);
    ios::sync_with_stdio(false);

    int n, mx = 0;
    cin >> n;
    si s;
    vi v(1005,0);
    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        s.insert(x);
        v[x]++;
        mx = max(mx, v[x]);
    }
    
    cout << mx << " " << s.size() << endl;    
    return 0;
}
