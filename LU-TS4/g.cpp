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
#define rev(x) (x).rbegin(),(x).rend()
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

    int n;
    vector<int> a;
    cin >> n;
    for(int i=0; i<n; i++)
    {
        int x;
        cin>>x;
        if(x%2!=0)
           a.pb(x-2);
        
        else
        for(int j=3; j<10000; j+=2)
        {
            if(x%j!=0)
            {
                a.pb(x-j);
                break;
            }
        }
    }
    int m=0,t=0;
    sort(rev(a));
    for(int i=0; i<n; i++)
    {
        if(i%2==0)
        {
            m+=a[i];
        }
        else
        {
            t+=a[i];
        }
    }
    cout<<m<<" "<<t<<endl;
    return 0;
}
