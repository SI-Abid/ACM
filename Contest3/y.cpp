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
#define all(x) (x).rbegin(),(x).rend()

typedef vector<int> vi;
typedef vector<ll> vll;
typedef set<int> si;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MOD = 1e9 + 7;
const int INF = 1e9;

bool com(pii a, pii b)
{
    // if(a.S==b.S)
    //     return a.F<b.F;
    // else
        return a.S>b.S;
}

int main(int argc, char* argv[])
{
    if(argc == 2 or argc == 3) freopen(argv[1], "r", stdin);
    if(argc == 3) freopen(argv[2], "w", stdout);
    ios::sync_with_stdio(false);

    vector<pll> vp;
    int n;
    cin>>n;
    while(n--)
    {
        ll x, y;
        cin>>x>>y;
        vp.push_back(mp(y,x));
    }
    
    sort(all(vp));
    
    for(auto g:vp)
    {
        cout<<g.S<<" "<<g.F<<endl;
    }

    return 0;
}
