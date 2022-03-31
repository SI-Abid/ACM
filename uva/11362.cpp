////////////////////////////////////////////////////////////////////////////////////////////
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


struct Node
{
    bool end;
    Node *next[26];
    Node()
    {
        for(int i=0;i<26;i++)
        {
            next[i]=NULL;
        }
        end=false;
    }
    bool insert(string s)
    {
        int len=s.size();
        Node *curr=this;
        for(int i=0;i<len;i++)
        {
            int index=s[i]-'0';
            if(curr->next[index]==NULL)
            {
                curr->next[index]=new Node();
            }
            curr=curr->next[index];
            if(curr->end==true)
            {
                return false;
            }
        }
        curr->end=true;
        return true;
    }
  
    void del(Node *cur)
    {
        for(int i=0;i<26;i++)
        {
            if(cur->next[i]!=NULL)
            {
                del(cur->next[i]);
            }
        }
        delete cur;
    }
};

int main(int argc, char* argv[])
{
    if(argc == 2 or argc == 3) freopen(argv[1], "r", stdin);
    if(argc == 3) freopen(argv[2], "w", stdout);
    ios::sync_with_stdio(false);

    int t;
    cin>>t;
    Node *root;
    while(t--)
    {
        int n;
        cin>>n;
        vector<string> v(n);
        for(int i=0;i<n;i++)
        {
            cin>>v[i];
        }
        sort(v.begin(),v.end(),[] (string a, string b) {return a.size()<b.size();});
     
        root=new Node();
        bool flag=true;
        for(int i=0;i<n;i++)
        {
            if(root->insert(v[i])==false)
            {
                flag=false;
                break;
            }
        }
        cout<<(flag?"YES\n":"NO\n");
        root->del(root);

    }
    return 0;
}