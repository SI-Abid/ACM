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

    int n; cin>>n;
    vi v(n);
    for (int i = 0; i < n; i++)
    {
        cin>>v[i];
    }
    int pos1=0,pos2=0, high1=-1,high2=-1;
    for (int i = 0; i < n; i++)
    {
        if(v[i]>high1)
        {
            high2=high1;
            high1=v[i];
            pos2=pos1;
            pos1=i+1;
        }
        else if(v[i]>high2)
        {
            high2=v[i];
            pos2=i+1;
        }
    }
    
    cout<<pos2<<endl;
    
    return 0;
}
