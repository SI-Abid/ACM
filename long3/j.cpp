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

int sumofdivisor(int n)
{
    int res = 0;
    for(int i = 2; i * i <= n; i++)
    {
        if(n % i == 0)
        {
            res+=i;
            // cout<<i<<" ";
            if(i * i != n)
            {
                res+=n / i;
                // cout<<n / i<<" ";
            }
        }
    }
    return res;
}

int main(int argc, char* argv[])
{
    if(argc == 2 or argc == 3) freopen(argv[1], "r", stdin);
    if(argc == 3) freopen(argv[2], "w", stdout);
    ios::sync_with_stdio(false);

    int t;
    cin >> t;
    while(t--)
    {
        int x, y;
        cin >> x >> y;
        int a = sumofdivisor(x);
        // cout<<endl;
        int b = sumofdivisor(y);
        // cout<<endl<<a<<" "<<b<<endl;
        if(a == y-1 && b == x-1)
        {
            cout << "Friendship is ideal\n";
        }
        else
        {
            cout << "Friendship is not ideal\n";
        }
    }    
    
    return 0;
}
