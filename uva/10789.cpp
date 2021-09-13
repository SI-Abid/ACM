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

vector<bool> p(2005, true);

void init()
{
    // memset(p, true, p.size());
    p[0]=p[1]=false;
    for(int i=4; i<=2005; i+=2)  p[i]=false;

    for (int i = 3; i*i <= 2005; i+=2)
    {
        for (int j = i*i; j <= 2005; j+=2*i)
        {
            p[j]=false;
        }
    }

}

int main(int argc, char* argv[])
{
    if(argc == 2 or argc == 3) freopen(argv[1], "r", stdin);
    if(argc == 3) freopen(argv[2], "w", stdout);
    ios::sync_with_stdio(false);

    int t;
    cin>>t;
    init();
    for (int tc = 1; tc <= t; tc++)
    {
        vi a(205, 0);
        // memset(a, 0, a.size());
        string s;
        cin>>s;

        for(char c:s)
        {
            int pos=c;
            a[pos]++;
        }
        cout<<"Case "<<tc<<": ";
        string o="";
        for (int i = 0; i < 205; i++)
        {
            if(p[a[i]])
            {
                o+=i;
            }
        }
        if(o.size())
            cout<<o;
        else
            cout<<"empty";
        // if(tc!=t)
            cout<<endl;    
    }
        
    
    return 0;
}
