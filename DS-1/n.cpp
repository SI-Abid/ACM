/**
 * data structure
 * segment tree
 * minimum element in subarray
 */

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

class str: public string
{
    public:
    void replace(char x, char y){ for (char &c:*this)if(c==x)c=y; }
};

#define mx 100005
int tree[3*mx], ar[mx];

void buildTree(int node, int start, int end)
{
    if(start == end)
    {
        tree[node]=ar[start];
        return;
    }
    int mid = (start+end)/2;
    int left = 2*node;
    int right = 2*node +1;
    buildTree(left, start, mid);
    buildTree(right, mid+1, end);
    tree[node] = min(tree[left], tree[right]);
    // cout<<node<<" "<<tree[node]<<" = ";
}

int query(int node, int start, int end, int left, int right)
{
    if(left>end || right<start)
    {
        return mx;
    }
    if(start>=left && end<=right)
    {
        // cout<<"* "<<node<<endl;
        return tree[node];
    }
    int l = node*2;
    int r = node*2+1;
    int mid = (start+end)/2;
    int left_min = query(l,start,mid,left,right);
    int right_min = query(r, mid+1, end,left,right);
    // cout<<left_min<<" <> "<<right_min<<endl;
    return min(left_min,right_min);
}

int main(int argc, char* argv[])
{
    if(argc == 2 or argc == 3) freopen(argv[1], "r", stdin);
    if(argc == 3) freopen(argv[2], "w", stdout);
    ios::sync_with_stdio(false);

    int t;
    cin>>t;
    for(int tc=1;tc<=t; tc++)
    {
        int n, k;
        cin>>n>>k;
        for (int i = 1; i <= n; i++)
        {
            cin>>ar[i];
        }
        buildTree(1,1,n);
        cout<<"Case "<<tc<<":"<<endl;
        int l,r;
        while(k--)
        {
            cin>>l>>r;
            cout<<query(1,1,n,l,r)<<endl;
            // cout<<"** ";
            // for (int i = 0; i < 2*n+2; i++)
            // {
            //     cout<<tree[i]<<" ";
            // }
            // cout<<"**"<<endl;
        }
        
    }
    
    return 0;
}
