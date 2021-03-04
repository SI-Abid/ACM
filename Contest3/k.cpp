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
bool p[2010];

void prime(int);

int main(int argc, char* argv[])
{
    if(argc == 2 or argc == 3) freopen(argv[1], "r", stdin);
    if(argc == 3) freopen(argv[2], "w", stdout);
    ios::sync_with_stdio(false);

    prime(2008);

    int n;
    cin>>n;
    for(int t=1; t<=n; t++)
    {
        map<char, int> m;
        string s;
        cin>>s;
        for(auto c:s)
            m[c]++;

        cout<<"Case "<<t<<": ";
        vector<char>v;
        for(auto it:m)
            if(p[it.S])
                v.pb(it.F);
        
        if(v.empty())
            cout<<"empty";
        else
        {
            for(auto i:v)
                cout<<i;
        }
        cout<<endl;
    }
    
    return 0;
}

void prime(int x)
{
    memset(p, true, sizeof(p)); 
    p[1]=false;
    for (int k=2; k*k<=x; k++) 
    { 
        if (p[k] == true) 
        { 
            for (int i=k*k; i<=x; i += k) 
                p[i] = false; 
        } 
    }
}
