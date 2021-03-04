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
#define checkvowel(c) (c=='a' || c=='e' || c=='i' || c=='o' || c=='u')

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

    map<string, string>mm;
    int n, m;
    string a, b;
    cin>>n>>m;
    while(n--)
    {
        cin>>a>>b;
        mm[a]=b;
    }
    while(m--)
    {
        cin>>a;
        int len=a.size()-1;
        if(mm[a].length()>1)
        {
            cout<<mm[a]<<endl;
        }
        else if(a[len]=='y' && !checkvowel(a[len-1]))
        {
            a.pop_back();
            cout<<a<<"ies"<<endl;
        }
        else if(a[len]=='o' || a[len]=='s' || a[len]=='x' || (a[len]=='h' && (a[len-1]=='c' || a[len-1]=='s')))
        {
            cout<<a<<"es"<<endl;
        }
        else
        {
            cout<<a<<"s"<<endl;
        }
    }
    return 0;
}
