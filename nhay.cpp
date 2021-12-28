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

int failure[100000];
vi pos;

void build(string pat, int size)
{
    failure[0]=failure[1]=0;

    for(int i=2; i<=size; i++)
    {
        int j=failure[i-1];
        while (true)
        {
            if(pat[j]==pat[i-1])
            {
                failure[i]=j+1;
                break;        
            }
            if(j==0)
            {
                failure[i]=0;
                break;
            }
            j=failure[j];
        }
    }
}

void kmp(string text, string pat)
{
    int n, m;
    n=text.size();
    m=pat.size();
    build(pat, m);

    int i, j;
    i=j=0;

    while(true)
    {
        if(j==n)
        {
            return;
        }
        if(text[j]==pat[i])
        {
            i++;
            j++;
            if(i==m)
            {
                pos.pb(j-i);
                i=failure[i];
            }
        }
        else
        {
            if(i==0)
                j++;
            else
                i=failure[i];
        }
    }
    return;
}

int main(int argc, char* argv[])
{
    if(argc == 2 or argc == 3) freopen(argv[1], "r", stdin);
    if(argc == 3) freopen(argv[2], "w", stdout);
    ios::sync_with_stdio(false);

    int n;
    while(cin>>n)
    {
        string needle, haystack;
        cin>>needle>>haystack;
        int m=haystack.size();
        if(n>m)
        {
            cout<<endl;
            continue;
        }
        pos.clear();
        kmp(haystack, needle);
        for(auto x:pos)
            cout<<x<<endl;
    }

    return 0;
}
