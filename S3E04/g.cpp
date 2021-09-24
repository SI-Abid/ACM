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
    string s; 
    cin>>s;
    map<char,char>mc;
    char cx='a';
    for(char c:s)
    {
        mc[c]=cx++;
    }
    vector<pair<string, string>> vec;
    int t;
    cin>>t;   

    for (int i = 0; i < t; i++)
    {
        string ss,temp="";
        cin>>ss;
        for (int i = 0; i < ss.size(); i++)
        {
            temp+=mc[ss[i]];
        }
        vec.pb({temp,ss});

    }

    sort(all(vec));

    // for(auto x = vs.rbegin(); x!=vs.rend(); x++)
    //     cout<<*x<<endl;
    for(auto x:vec)
        cout<<x.S<<endl;
        
    return 0;
}