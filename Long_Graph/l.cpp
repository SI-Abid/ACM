////////////////////////////////////////////////////////////////////////////////////////////
// Type: Graph DP

#include <bits/stdc++.h>
using namespace std;

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
#define pcase(x) cout << "Case " << x << ":";
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

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int vis[500][500];
char grid[500][500];
int save[3000];
int term;

void dfs(int x, int y, int r, int c)
{
    vis[x][y] = term;
    if(grid[x][y] == 'C')
        save[term]++;
    for(int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx >= 0 and nx < r and ny >= 0 and ny < c and vis[nx][ny]==0)
        {
            if(grid[nx][ny] != '#')
                dfs(nx, ny, r, c);
        }
    }
}

int main(int argc, char* argv[])
{
    if(argc == 2 or argc == 3) freopen(argv[1], "r", stdin);
    if(argc == 3) freopen(argv[2], "w", stdout);
    ios::sync_with_stdio(false);

    int t;cin>>t;


    rep(tc,1,t+1)
    {
        memset(vis, 0, sizeof vis);
        memset(save, 0, sizeof save);
        memset(grid, 0, sizeof grid);

        int row, col, q;
        cin>>row>>col>>q;
        rep(i,0,row)
            rep(j,0,col)
                cin>>grid[i][j];

        pcase(tc);
        cout<<endl;
        term = 1;
        rep(i,0,q)
        {
            int x,y;
            cin>>x>>y;
            x--;y--;
            if(vis[x][y]==0)
            {
                dfs(x, y, row, col);
                term++;
            }
            
            cout<<save[vis[x][y]]<<endl;
        }
    }

    return 0;
}
