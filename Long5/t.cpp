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

const int MX = 1e8 + 5;

int mark[MX];
pii p[1000000];
bool check(int n, int pos)
{
    return (bool) (n&(1<<pos));
}
int Set(int n, int pos)
{
    return n=n|(1<<pos);
}
void bitwiseSieve()
{
    for(int i = 3; i*i <= MX; i+=2)
        if(check(mark[i>>5], i%32)==0)                  // check bit
            for(int j = i*i; j <= MX; j+=i*2)
                mark[j>>5] = Set(mark[j>>5],j%32);      // set bits to 1

}
void twinPrime()
{
    int pi = 0;
    for(int i = 3; i <= MX-2; i+=2)
    {
        if(check(mark[i>>5], i%32)==0 && check(mark[i+2>>5], (i+2)%32)==0)
        {
            p[pi++] = {i, i+2};
        }
    }
}
int main(int argc, char* argv[])
{
    if(argc == 2 or argc == 3) freopen(argv[1], "r", stdin);
    if(argc == 3) freopen(argv[2], "w", stdout);
    ios::sync_with_stdio(false);

    int n;
    // clock_t t1 = clock();
    bitwiseSieve();
    twinPrime();
    // t1 = clock() - t1;
    // cout << "Time: " << t1/CLOCKS_PER_SEC << "s" << endl;
    while(cin>>n)
    {
        cout << "(" << p[n-1].F << ", " << p[n-1].S << ")" << "\n";
    }
    
    return 0;
}
