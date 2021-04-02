#include <bits/stdc++.h>
using namespace std;

#define PI 3.14159265
#define ll long long
#define ull unsigned long long
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define be begin()
#define en end()
#define all(x) (x).begin(), (x).end()
#define out cout << setprecision(12)

typedef vector<int> vi;
typedef vector<ll> vll;
typedef set<int> si;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MOD = 1e9 + 7;
const int INF = 1e9;

double dist(double x1, double y1, double x2, double y2)
{
    double dx=abs(x1-x2);
    double dy=abs(y1-y2);
    double tmp=dx*dx + dy*dy;
    assert(tmp>=0);
    return sqrt(tmp);
}

void solve()
{
    int n, x, p, q;
    cin >> n;
    vector<double> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    cin >> p >> q;
    auto pa = minmax_element(all(v));
    double x1 = *pa.first, x2 = *pa.second;

    double a, b, c;
    c = x2 - x1;
    a = dist(p, q, x1, 0);
    b = dist(p, q, x2, 0);
    double param = (a * a + b * b - c * c) / (2 * a * b);
    // cout << a << " " << b << " " << c << " " << x1 << " " << x2 << " "<<param<<endl;
    double C = acos(param);
    // C = C * PI / 180.0;

    printf("%0.12lf\n", C);
    // out << C << endl;
}

int main(int argc, char *argv[])
{
    if (argc == 2 or argc == 3)
        freopen(argv[1], "r", stdin);
    if (argc == 3)
        freopen(argv[2], "w", stdout);
    ios::sync_with_stdio(false);

    int t;
    for (cin >> t; t; t--)
        solve();

    return 0;
}
