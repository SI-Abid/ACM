#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
// #include <pair>
#include <set>
#include <queue>
#include <stack>

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
const int MX = 1e5 + 5;

bool mark[MX];
vi prime;

// sieve of eratosthenes
void sieve() {
    for (int i = 2; i < MX; i++) {
        if (!mark[i]) {
            prime.pb(i);
            for (int j = i * i; j < MX; j += i) {
                mark[j] = 1;
            }
        }
    }
}


int main(int argc, char* argv[])
{
    if(argc == 2 or argc == 3) freopen(argv[1], "r", stdin);
    if(argc == 3) freopen(argv[2], "w", stdout);
    ios::sync_with_stdio(false);

    sieve();
    for(int i = 0; i < prime.size(); i++) {
        cout << prime[i] << " ";
    }
    
    return 0;
}
