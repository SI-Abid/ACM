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

void solve()
{
    int k,g,n;
    cin>>k>>g>>n;
    vi h(n),s(n);
    
    for(auto &x: h)
        cin>>x;
    for(auto &x: s)
        cin>>x;

    sort(all(h));
    sort(all(s));

    ll p=k*g, ans=1;
    bool flag=false;
    int pos=n-1;

    for(int i=0; i<n; i++)
    {
        while(pos>=0 and h[pos]*s[i]>p)
        {
            pos--;
        }
        if(n-pos-i+1<=0)
        {
            flag=true;
            break;
        }
        ans*=(n-pos-i-1)%MOD;
    }
    flag?cout<<"0\n":out<<ans<<endl;
}

int main(int argc, char* argv[])
{
    if(argc == 2 or argc == 3) freopen(argv[1], "r", stdin);
    if(argc == 3) freopen(argv[2], "w", stdout);
    ios::sync_with_stdio(false);

    int t, i=1;
    for(cin>>t;t;t--)
    {
        cout<<"Case "<<i++<<": ";
        solve();
    }
    
    return 0;
}
