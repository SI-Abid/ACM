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

int getMax(int *a, int sz)
{
    int mx = a[0];
    int idx = 0;
    for(int i = 1; i < sz; i++)
        if(a[i] > mx)
        {
            mx = a[i];
            idx=i;
        }
    return idx;
}

int main(int argc, char* argv[])
{
    if(argc == 2 or argc == 3) freopen(argv[1], "r", stdin);
    if(argc == 3) freopen(argv[2], "w", stdout);
    ios::sync_with_stdio(false);

    int t;
    cin >> t;
    string s[t];
    int height[t];
    for (int i = 0; i < t; i++)
    {
        cin>>s[i]>>height[i];
    }
    int fir = getMax(height, t);
    height[fir] = -1;
    int sec = getMax(height, t);
    cout << s[sec] << endl;
    return 0;
}
