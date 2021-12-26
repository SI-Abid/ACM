////////////////////////////////////////////////////////////////////////////////////////////
#include <bits/stdc++.h>
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


vector<vector<int>> gis(vector<string> s)
{
    int n=s.size();
    vector<pair<ll, int>>hashes(n);
    
    for(int i=0;i<n;i++)
        hashes[i]={hash_text(s[i]),i};
    
    sort(hashes.begin(), hashes.end());

    vector<vi> groups;
    for (int i = 0; i < n; i++)
    {
        if(i==0 || hashes[i].first != hashes[i-1].first)
            groups.emplace_back();  // adding new container at the end

        groups.back().push_back(hashes[i].second);  // items pushed in the last container
    }
    return groups;
}

ll hash_text(string s)
{
    ll ans=0;
    ll p=31;
    ll m=1e9+9;
    ll pp=1;
    for(char c: s)
    {
        ans+=((c-96)*pp)%m;
        pp*=p;
    }
    return ans;
}

int main(int argc, char* argv[])
{
    if(argc == 2 or argc == 3) freopen(argv[1], "r", stdin);
    if(argc == 3) freopen(argv[2], "w", stdout);
    ios::sync_with_stdio(false);

    

    return 0;
}
