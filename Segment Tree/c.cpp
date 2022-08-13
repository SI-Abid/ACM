//////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////🔥//🔥//🔥///One///touch////and////I///Ignite///🔥//🔥//🔥/////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////
#include <bits/stdc++.h>
using namespace std;

#define cls system("clear")
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
#define all(x) (x).begin(), (x).end()
#define out cout << setprecision(20)
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define what_is(x) cout << #x << " is " << x << endl;
#define error(args...)                           \
    {                                            \
        string _s = #args;                       \
        replace(_s.begin(), _s.end(), ',', ' '); \
        stringstream _ss(_s);                    \
        istream_iterator<string> _it(_ss);       \
        err(_it, args);                          \
    }
#define pcase(x) cout << "Case " << x << ": ";
void err(istream_iterator<string> it)
{
}
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args)
{
    cerr << *it << " = " << a << endl;
    err(++it, args...);
}

typedef vector<int> vi;
typedef vector<ll> vll;
typedef set<int> si;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MOD = 1e9 + 7;
const int INF = 1e9;
const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};
const int fx[] = {0, 1, 1, 1, 0, -1, -1, -1};
const int fy[] = {1, 1, 0, -1, -1, -1, 0, 1};

struct Node
{
    int val;
    Node *left, *right;
    Node(int v)
    {
        val = v;
        left = right = NULL;
    }
};
/*
            [1, 2, 3, 4] (1)
                        /   \
               [1, 2] (1)   (3) [3, 4]
                     /  \   /  \
                   (1) (2) (3) (4)

*/
void build(Node *root, int l, int r, vector<int> &v)
{
    if (l == r) // leaf node
    {
        root->val = v[l - 1];
        return;
    }
    int mid = (l + r) / 2;
    root->left = new Node(0);       // divide
    build(root->left, l, mid, v);
    root->right = new Node(0);
    build(root->right, mid + 1, r, v);  // divide
    root->val = min(root->left->val, root->right->val); // parent nodes | conquer
}

int query(Node *root, int l, int r, int i, int j)
{
    if (i > r || j < l)
        return INF;
    if (l >= i && r <= j)
        return root->val;
    int mid = (l + r) / 2;
    return min(query(root->left, l, mid, i, j), query(root->right, mid + 1, r, i, j));
}

int main(int argc, char *argv[])
{
    if (argc == 2 or argc == 3)
        freopen(argv[1], "r", stdin);
    if (argc == 3)
        freopen(argv[2], "w", stdout);
    ios::sync_with_stdio(false);

    int t, tc = 0;
    cin >> t;
    while (t--)
    {
        int n, q;
        cin >> n >> q;
        vector<int> v(n);
        rep(i, 0, n) cin >> v[i];
        Node *root = new Node(0);
        build(root, 1, n, v);
        cout << "Case " << ++tc << ":\n";
        while (q--)
        {
            int l, r;
            cin >> l >> r;
            cout << query(root, 1, n, l, r) << '\n';
        }
    }
    return 0;
}
