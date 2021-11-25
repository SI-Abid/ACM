#include <iostream>
#include <string>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <list>
#include <set>
#include <cmath>
#include <cstring>

#include <stdio.h>
#include <string.h>
#include <sstream>
#include <stdlib.h>
#include <vector>
#include <iomanip>
#include <ctime>

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

void solve() 
{
    ll n;
    cin >> n;
    ll r, c;
    ll rt = ceil(sqrt((double)n));
    ll l = rt*rt - n;
    c = rt;
    rt--;
    r = n - rt*rt;
    if(l<rt)
    {
        r = c;
        c=l+1;
    }
    if(rt&1)
    {
        cout<<r<<" "<<c<<endl;
    }
    else
    {
        cout<<c<<" "<<r<<endl;
    }
}

int main(int argc, char* argv[])
{
    if(argc == 2 or argc == 3) freopen(argv[1], "r", stdin);
    if(argc == 3) freopen(argv[2], "w", stdout);
    ios::sync_with_stdio(false);

    int t;
    cin>>t;
    for(int tc=1; tc<=t; tc++)
    {
        cout<<"Case "<<tc<<": ";
        solve();
    }
    
    return 0;
}
