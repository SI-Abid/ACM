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

    vector<string> rat, cap, man, wom;
    int n;
    string a, b;
    cin>>n;
    while(n--)
    {
        cin>>a>>b;
        if(b=="captain")
        {
            cap.push_back(a);
        }
        else if(b=="child" || b=="woman")
        {
            wom.pb(a);
        }
        else if(b=="man")
        {
            man.pb(a);
        }
        else
        {
            rat.pb(a);
        }   
    }
    for(auto x:rat)
        cout<<x<<endl;
    for(auto x:wom)
        cout<<x<<endl;
    for(auto x:man)
        cout<<x<<endl;
    for(auto x:cap)
        cout<<x<<endl;
        
    return 0;
}
