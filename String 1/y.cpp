////////////////////////////////////////////////////////////////////////////////////////////
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define be begin()
#define en end()
#define rb rbegin()
#define re rend()
#define all(x) (x).begin(),(x).end()
#define out cout<<setprecision(20)

typedef vector<int> vi;
typedef vector<ll> vll;
typedef set<int> si;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MOD = 1e9 + 7;
const int INF = 1e9;


int solve(string s, int l)
{
    int n=s.size();
    int p=31;
    int m=1e9+9;
    vll pp(n);
    pp[0]=1;
    for(int i=1;i<n;i++)
        pp[i]=(pp[i-1]*p);

    vll hashes(n+1,0);
    for(int i=0;i<n;i++)
        hashes[i+1]=(hashes[i]+(s[i]-96)*pp[i]);

    set<ll> st;
    for(int i=0;i<=n-l;i++)
    {
        ll cur_hash = (hashes[i+l]-hashes[i]);
        cur_hash = (cur_hash*pp[n-i-1]);
        st.insert(cur_hash);
    }
    return st.size();
}

int main(int argc, char* argv[])
{
    if(argc == 2 or argc == 3) freopen(argv[1], "r", stdin);
    if(argc == 3) freopen(argv[2], "w", stdout);
    ios::sync_with_stdio(false);

    // freopen("in", "r", stdin);

    int t;
    cin>>t;
    while(t--)
    {
        int n,l;
        cin>>n>>l;
        string s;
        cin>>s;
        cout<<solve(s,l)<<endl;
    }

    return 0;
}
