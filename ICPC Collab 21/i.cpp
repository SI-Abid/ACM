////////////////////////////////////////////////////////////////////////////////////////////
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define F first
#define S second
#define be begin()
#define en end()
#define rb rbegin()
#define re rend()
#define all(x) (x).begin(),(x).end()
#define out cout<<setprecision(20)
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define what_is(x) cout << #x << " is " << x << endl;
#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) { cerr << *it << " = " << a << endl; err(++it, args...); }

typedef vector<int> vi;
typedef vector<ll> vll;
typedef set<int> si;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MOD = 1e9 + 7;
const int INF = 1e9;

string toBin(ll n)
{
    string s="";
    while(n)
    {
        s=char(n%2+'0')+s;
        n >>= 1;
    }
    // reverse(all(s));
    return s;
}

int main(int argc, char* argv[])
{
    if(argc == 2 or argc == 3) freopen(argv[1], "r", stdin);
    if(argc == 3) freopen(argv[2], "w", stdout);
    ios::sync_with_stdio(false);

    int t;
    cin>>t;
    // int bin[][62];
    
    while(t--)
    {
        ll m,n;
        cin>>m>>n;
        m = (1LL<<m)-1;
        // string a,b;
        // a=toBin(m);
        // b=toBin(n);
        // int cnt=0;
        // for(int i=0;i<a.size();i++)
        // {
        //     if(a[i]!=b[i])
        //         cnt++;   
        // }
        // // error(m,n,cnt);
        // cout<<m-cnt+1<<endl;
        cout<<m<<endl;
    }

    return 0;
}


/*

0 -> 0 0 0 0    0 0 0 0
1 -> 0 0 0 1    0 0 0 1
2 -> 0 0 1 1    0 0 1 0
3 -> 0 0 2 2    0 0 1 1
4 -> 0 1 2 2    0 1 0 0
5 -> 0 2 2 3    0 1 0 1
6 -> 0 3 3 3    0 1 1 0
7 -> 0 4 4 4    0 1 1 1
8    1 4 4 4    1 0 0 0
9    2 4 4 5    1 0 0 1
10   3 4 5 5    1 0 1 0
11   4 4 6 6    1 0 1 1
12   5 5 6 6    1 1 0 0
13   6 6 6 7    1 1 0 1
14   7 7 7 7    1 1 1 0
15   8 8 8 8    1 1 1 1

4 6
15

5 -> 0 1 1 0
---- 0 3 3 4

*/