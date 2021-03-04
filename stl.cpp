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
typedef vector<string> vs;
typedef set<int> si;
typedef set<string> ss;
typedef pair<int, int> pii;
typedef pair<string, int> psi; 
typedef pair<ll, ll> pll;

const int MOD = 1e9 + 7;
const int INF = 1e9;

void permuteN(int);
bool search(vi, int);
void solve1();
void solve2();

int main(int argc, char* argv[])
{
    if(argc == 2 or argc == 3) freopen(argv[1], "r", stdin);
    if(argc == 3) freopen(argv[2], "w", stdout);
    ios::sync_with_stdio(false);

    solve1();
    // solve2();

    return 0;
}

void solve1()
{
    map<string, int> MAP;
    string ns;
    getline(cin, ns);
    transform(ns.be, ns.en, ns.be, ::tolower);

    istringstream split(ns);
    string token;
    split>>token;
    
    while(split)
    {
        MAP[token]++;
        split>>token;
    }

    puts("  Words \t Count ");
    for(auto it=MAP.be; it!=MAP.en; it++)
    {
        cout << setw(6) << it->first <<"   "<< setw(4)<<it->second << endl;
    }
}

void solve2()
{
    si st;
    int n, x;
    cin>>n;
    while(n--)
    {
        cin>>x;
        st.insert(x);
    }
    cout<<st.size()<<endl;
}










bool search(vi vec, int it)
{
    sort(all(vec));
    return binary_search(all(vec), it);
}

void permuteN(int m)
{
    vi v;
    for(int i=1; i<=m; i++)
        v.pb(i);
    
    do
    {
        for(auto x:v)
            cout<<x<<" ";
        cout<<endl;
        
    }while(next_permutation(v.be, v.en));
    
}