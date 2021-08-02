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

    int fact[]={1,1,2,6,24,120,720,5040,40320,362880,3628800,39916800,479001600};
    int n;
    cin >> n;
    int tot=0;
    for (int i = 12; i >= 1 and n>0; i--)
    {
        if (n >= fact[i])
        {
            int cnt=0;
            while(n >= fact[i] and cnt < 100)
            {
                n -= fact[i];
                cnt++, tot++;
            }
        }
    }
    cout<<tot<<endl;
    return 0;
}
