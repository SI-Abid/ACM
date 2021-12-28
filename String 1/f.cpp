// knuth morris pratt
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
int kmp(string text, string pat, vector<int> v)
{
    int n, m;
    n=text.size();
    m=pat.size();
    build(pat, m);

    int i, j, cnt, k;
    i=j=cnt=0, k=1;

    while(true)
    {
        if(j==n)
        {
            return cnt;
        }
        if(text[j]==pat[i])
        {
            i++;
            j++;
            if(i==m)
            {
                cnt++;
                j=v[k++];
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
    return cnt;
}

int main(int argc, char* argv[])
{
    if(argc == 2 or argc == 3) freopen(argv[1], "r", stdin);
    if(argc == 3) freopen(argv[2], "w", stdout);
    ios::sync_with_stdio(false);

    int n,t;
    cin>>n>>t;
    string s="";
    vi v;
    v.pb(0);
    for(int i=0;i<n;i++)
    {
        string temp;
        cin>>temp;
        s+=temp;
        v.pb(v.back()+temp.size());
    }
    // v.pop_back();
    for(int i=0;i<t;i++)
    {
        int ans=0;
        string pat;
        cin>>pat;
        cout<<kmp(s,pat,v)<<endl;
    }   

    return 0;
}
