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
int main()
{
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    vi v(n),c(n);
    for(int i=0;i<n;i++)
        cin>>v[i];

    for(int i=0;i<n;i++)
        cin>>c[i];
    int sum=0;
    for(int i=0;i<n;i++)
    {
        if(v[i]-c[i]>0)
        {
            sum+=(v[i]-c[i]);
        }
    }
    cout<<sum<<endl;
    return 0;
}
