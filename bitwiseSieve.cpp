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

const int MX = 1e7 + 5;
int mark[MX];
vi prime;

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

    prime.pb(2);
    for(int i = 3; i < MX; i+=2)
        if(check(mark[i>>5], i%32)==0)
            prime.pb(i);
}

int main(int argc, char* argv[])
{
    if(argc == 2 or argc == 3) freopen(argv[1], "r", stdin);
    if(argc == 3) freopen(argv[2], "w", stdout);
    ios::sync_with_stdio(false);
    // freopen("bitwiseSieve.out", "w", stdout);
    // clock_t t1 = clock();
    bitwiseSieve();
    // clock_t t2 = clock();

    for(int i = 0; i < prime.size(); i+=100)
        cout<<prime[i]<<endl;

    // cout<<"Time: "<<(t2-t1)/CLOCKS_PER_SEC <<"s\n";
    // cout<<"Memory: "<<(double)sizeof(mark)/1024/1024<<"MB\n";
    // cout<<"Prime: "<<prime.size()<<"\n";
    
    // prime.clear();
    return 0;
}
