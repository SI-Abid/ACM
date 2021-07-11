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

int main(int argc, char* argv[])
{
    if(argc == 2 or argc == 3) freopen(argv[1], "r", stdin);
    if(argc == 3) freopen(argv[2], "w", stdout);
    ios::sync_with_stdio(false);

    ll n, cnt=1;
    cin>>n;
    vll a(n);
    for (ll i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    sort(all(a));
    
    for (int i = 0; i < n-1; i++)
    {
        if(a[i]==a[i+1])
            cnt++;
    }
    
    
    cout<<cnt<<endl;

    return 0;
}


// 1 1 2 3 4 4 6 7 8 8