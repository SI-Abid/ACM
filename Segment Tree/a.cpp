/////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////🔥//🔥//🔥///One///touch////and////I///Ignite///🔥//🔥//🔥////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////
#include <bits/stdc++.h>
using namespace std;

#define cls system("clear");
#define ll long long
#define ull unsigned long long
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define F first
#define S second
#define be begin()
#define en end()
#define rb rbegin()
#define re rend()
#define all(x) (x).begin(),(x).end()
#define out cout<<setprecision(20)
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define what_is(x) cout << #x << " is " << x << endl;
#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
#define pcase(x) cout << "Case " << x << ": ";
void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) { cerr << *it << " = " << a << endl; err(++it, args...); }

typedef vector<int> vi;
typedef vector<ll> vll;
typedef set<int> si;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MOD = 1e9 + 7;
const int INF = 1e9;
const int dx[]={0,0,1,-1};
const int dy[]={1,-1,0,0};
const int fx[]={0,1,1,1,0,-1,-1,-1};
const int fy[]={1,1,0,-1,-1,-1,0,1};

struct node
{
    int val;
    node *left,*right;
    node(int v)
    {
        val=v;
        left=right=NULL;
    }
};
void build(node *root, int l, int r, vector<int> &v)
{
    if(l==r)
    {
        root->val=v[l];
        return;
    }
    int mid=(l+r)/2;
    root->left=new node(0);
    root->right=new node(0);
    build(root->left,l,mid,v);
    build(root->right,mid+1,r,v);
    root->val=root->left->val+root->right->val;
}

void update(node *root, int l, int r, int i, int val)
{
    if(l==r)
    {
        root->val+=val==0?-root->val:val;
        return;
    }
    int mid=(l+r)/2;
    if(i<=mid)
        update(root->left,l,mid,i,val);
    else
        update(root->right,mid+1,r,i,val);
    root->val=root->left->val+root->right->val;
}

int query(node *root, int l, int r, int i, int j)
{
    if(l>j || r<i)
        return 0;
    if(l>=i && r<=j)
        return root->val;
    int mid=(l+r)/2;
    return query(root->left,l,mid,i,j)+query(root->right,mid+1,r,i,j);
}

int main()
{
    int t;
    cin>>t;
    int tc=0;
    while(t--)
    {
        int n,q;
        cin>>n>>q;
        vector<int> v(n);
        for(int i=0;i<n;i++)
            cin>>v[i];
        node *root=new node(0);
        build(root,0,n-1,v);
        cout<<"Case "<<++tc<<":\n";
        while(q--)
        {
            int type,l,r,val,i;
            cin>>type;
            if(type==1)
            {
                cin>>i;
                cout<<query(root,0,n-1,i,i)<<'\n';
                update(root,0,n-1,i,0);
            }
            else if(type==2)
            {
                cin>>i>>val;
                update(root,0,n-1,i,val);
            }
            else
            {
                cin>>l>>r;
                cout<<query(root,0,n-1,l,r)<<'\n';
            }
        }
    }
    return 0;
}