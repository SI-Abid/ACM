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

    int n;
    cin>>n;
    vi ar(n);
    for(int &x:ar)
        cin>>x;
    int mn=*min_element(ar.be, ar.en);
    vi pos;
    for(int i=0;i<n;i++)
    {
        if(ar[i]==mn)
            pos.pb(i);
    }
    int d=INF;
    for(int i=1; i<pos.size(); i++)
    {
        d=min(d,pos[i]-pos[i-1]);
    }
    cout<<d<<endl;
    return 0;
}
