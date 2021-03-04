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

int main(int argc, char* argv[])
{
    if(argc == 2 or argc == 3) freopen(argv[1], "r", stdin);
    if(argc == 3) freopen(argv[2], "w", stdout);
    ios::sync_with_stdio(false);

    int n,q;
    cin>>n>>q;
    int c[n+1]={0}, col[n+1]={0};
    for(int i=1; i<=n; i++)
    {
        cin>>c[i];
        if(col[c[i]]==0)
        {
            col[c[i]]=1;
            c[i]=c[i-1]+1;
        }
        else
        {
            c[i]=c[i-1];
        }
        
    }
    int l,r;
    while(q--)
    {
        cin>>l>>r;
        cout<<c[r]-c[l]+1<<endl;
    }
    return 0;
}
