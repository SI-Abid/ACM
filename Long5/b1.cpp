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

vi arrayofdivisor(int n)
{
    vi res;
    for(int i = 1; i * i <= n; i++)
    {
        if(n % i == 0)
        {
            res.pb(i);
            if(i * i != n)
                res.pb(n / i);
        }
    }
    sort(all(res));
    return res;
}

int main(int argc, char* argv[])
{
    if(argc == 2 or argc == 3) freopen(argv[1], "r", stdin);
    if(argc == 3) freopen(argv[2], "w", stdout);
    ios::sync_with_stdio(false);

    int n; cin >> n;
    vi divisors = arrayofdivisor(n);
    for(auto x : divisors)
    {
        cout << x << " ";
    }
    return 0;
}