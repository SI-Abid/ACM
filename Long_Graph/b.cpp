////////////////////////////////////////////////////////////////////////////////////////////
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

int ans=0;

int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
bool visited[100][100];

void graph(vector<vector<char>> v, int x, int y)
{
    // error(x,y,v[x][y],ans);
    visited[x][y] = true;
    for(int i=0; i<4; i++)
    {
        int nx = x+dx[i];
        int ny = y+dy[i];
        if(nx>=0 and nx<v.size() and ny>=0 and ny<v[0].size() and !visited[nx][ny])
        {
            visited[nx][ny] = true;
            if(v[nx][ny]=='.')
            {
                ans++;
                graph(v, nx, ny);
            }
        }
    }
}

int main(int argc, char* argv[])
{
    if(argc == 2 or argc == 3) freopen(argv[1], "r", stdin);
    if(argc == 3) freopen(argv[2], "w", stdout);
    ios::sync_with_stdio(false);

    int t;cin>>t;
    rep(c,0,t)
    {
        int row,col;
        cin>>col>>row;
        vector<vector<char>> s(row,vector<char>(col));
        int sx,sy;
        rep(i,0,row)
        {
            rep(j,0,col)
            {
                cin>>s[i][j];
                if(s[i][j]=='@')
                {
                    sx=i;
                    sy=j;
                }
            }
        }
        memset(visited,false,sizeof(visited));
        ans = 0;
        graph(s,sx,sy);
        cout<<"Case "<<c+1<<": "<<ans+1<<endl;
    }

    return 0;
}
