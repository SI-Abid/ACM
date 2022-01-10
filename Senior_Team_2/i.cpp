////////////////////////////////////////////////////////////////////////////////////////////
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define F first
#define S second
#define be begin()
#define en end()
#define rb rbegin()
#define re rend()
#define all(x) (x).begin(),(x).end()
#define out cout<<setprecision(20)
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define what_is(x) cout << #x << " is " << x << endl;
#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) { cerr << *it << " = " << a << endl; err(++it, args...); }

typedef vector<int> vi;
typedef vector<ll> vll;
typedef set<int> si;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MOD = 1e9 + 7;
const int INF = 1e9;

bool colide(pii a, pii b)
{
    return (b.F >= a.F and b.F <= a.S) or (b.S >= a.F and b.S <= a.S);
}

int main(int argc, char* argv[])
{
    if(argc == 2 or argc == 3) freopen(argv[1], "r", stdin);
    if(argc == 3) freopen(argv[2], "w", stdout);
    ios::sync_with_stdio(false);

    int n,m;
    while(cin>>n>>m)
    {
        if(n+m==0) break;
        vector<pii> v;
        int cnt,x,y;
        rep(i,0,n)
        {
            cin>>x>>y>>x>>y;
            v.pb({x,x+y-1});
        }
        rep(i,0,m)
        {
            cnt=0;
            cin>>x>>y;
            rep(j,0,n)
            {
                if(colide(v[j],{x,x+y-1}))
                    cnt++;
            }
            cout<< cnt << endl;
        }
    }

    return 0;
}
