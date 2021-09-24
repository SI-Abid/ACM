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

class str: public string
{
    public:
    void replace(char x, char y){ for (char &c:*this)if(c==x)c=y; }
};


int main()
{
    str s;
    cin>>s;
    s.replace(',',' ');
    cout<<s<<endl;
    
    return 0;
}