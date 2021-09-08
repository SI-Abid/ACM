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

    string p;
    cin>>p;
    if(p[0]==p[1] && p[1]==p[2] && p[2]==p[3])
    {
        cout<<"Weak"<<endl;
    }
    else
    {
        bool weak=true;
        for (int i = 0; i < 3; i++)
        {
            if((p[i]+1-'0')%10!=p[i+1]-'0')
            {
                weak=false;
                break;
            }
        }
        puts(weak?"Weak":"Strong");
    }
    
    return 0;
}
