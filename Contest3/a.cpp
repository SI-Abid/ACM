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

    set<string> vs;
    // char c;
    string s, t, sp;
    while(getline(cin, sp))
    {
        for(auto c:sp)
            s.operator+=(c);
        // cin.ignore();
        s.operator+=(" ");
    }
    for(int i=0; i<s.size(); i++)
    {
        t="";
        while(isalpha(s[i]) && i<s.size())
        {
            t+=tolower(s[i]);
            i++;
        }
        vs.insert(t);
    }
    // sort(all(vs));
    for(auto x:vs)
    {
        if(x.size())
            cout<<x<<endl;
    }    
    return 0;
}
