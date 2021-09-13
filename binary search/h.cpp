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


int nb,ns,nc,pb,ps,pc;
int bun,sos,cis;

ll cost(ll x)
{
    ll fb,fc,fs;
    fb = max(x*bun - nb, (ll)0);
	fs = max(x*sos - ns, (ll)0);
	fc = max(x*cis - nc, (ll)0);

	ll p = fb*pb + fc*pc + fs*ps;
	return p;
}

int main(int argc, char* argv[])
{
    if(argc == 2 or argc == 3) freopen(argv[1], "r", stdin);
    if(argc == 3) freopen(argv[2], "w", stdout);
    ios::sync_with_stdio(false);

    string s;
    cin>>s;

    bun=sos=cis=0;
    for(char c:s)
    {
        if(c=='B')  bun++;
        else if(c=='S') sos++;
        else    cis++;
    }
    ll r;
    cin>>nb>>ns>>nc>>pb>>ps>>pc>>r;

    ll low,high,mid,t,ans;
    low=0, high=r+100;

    while (low<=high)
    {
        mid=(low+high)/2;
        t=cost(mid);
        if(t==r)
        {
            cout<<mid<<endl;
            return 0;
        }
        if(t>r)
        {
            high=mid-1;
        }
        else
        {
            low=mid+1;
            ans=mid;
        }
    }
    cout<<ans<<endl;
    return 0;
}
