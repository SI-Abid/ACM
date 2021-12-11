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

int main(int argc, char* argv[])
{
    if(argc == 2 or argc == 3) freopen(argv[1], "r", stdin);
    if(argc == 3) freopen(argv[2], "w", stdout);
    ios::sync_with_stdio(false);

    vector<int> v;
    v.pb(0);
    int i=2;
    for(int j=1; j<=1000000;)
    {
        v.pb(j);
        j+=i;
        i++;
    }
    // for(int i=1; i<=999; i++)
    // {
    //     printf("Index %4d Building %4d\n", i, v[i]);
    // }
    int a,b;
    cin>>a>>b;
    cout<<v[b-a]-b<<endl;
    return 0;
}
