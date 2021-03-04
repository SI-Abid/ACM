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

    int n;
    while(cin>>n && n!=0)
    {
        priority_queue<int, vector<int>, greater<int> > p;
        ll ans=0;
        int x, a, b;
        for(int i=0; i<n; i++)
        {
            cin>>x;
            p.push(x);
        }
        while(p.size()>1)
        {
            a=p.top();
            p.pop();
            b=p.top();
            p.pop();
            ans+=a+b;
            p.push(ans);
        }
        cout<<p.top()<<endl;
    }
    
    return 0;
}