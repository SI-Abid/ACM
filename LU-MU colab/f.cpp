#include "bits/stdc++.h"
using namespace std;

// #define ll long long int
#define ll unsigned long long
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define be begin()
#define en end()
#define all(x) (x).begin(), (x).end()
#define out cout << setprecision(20)

typedef vector<int> vi;
typedef vector<ll> vll;

vector<ll>::iterator it;

int main()
{
    int t,like,n;
    ll x;
    cin >> t;
    vll aa, bb;
    bool fetch = true, petch=true;
    while (t--)
    {
        cin >> like >> n;
        vll cc;
        while (n--)
        {
            cin >> x;
            cc.pb(x);
        }
        if (like == 1)
        {
            if (fetch)
            {
                aa = cc;
                fetch = false;
                continue;
            }
            it = set_intersection(all(aa), all(cc), aa.begin());
            aa.resize(it - aa.begin());
        }
        else
        {
            if(petch)
            {
                bb=cc;
                petch=false;
                continue;
            }
            it = set_union(all(bb), all(cc), bb.begin());
            bb.resize(it - bb.begin());
        }
    }
    // vll fin(1);
    it = set_difference(all(aa), all(bb), aa.begin());

    cout << it - aa.begin() << endl;
    return 0;
}