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
typedef vector<pii> vpii;

const int MOD = 1e9 + 7;
const int INF = 1e9;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
bool visited[100][100];

int main(int argc, char* argv[])
{
    if(argc == 2 or argc == 3) freopen(argv[1], "r", stdin);
    if(argc == 3) freopen(argv[2], "w", stdout);
    ios::sync_with_stdio(false);

    int t;cin>>t;
    rep(c,1,t+1)
    {
        int row,col;
        cin>>row>>col;
        char grid[row][col];
        vpii girls(3);
        rep(i,0,row)
        {
            rep(j,0,col)
            {
                cin>>grid[i][j];
                if(grid[i][j] == 'a' or grid[i][j] =='b' or grid[i][j]=='c')
                {
                    girls[grid[i][j]-'a']={i,j};
                    grid[i][j]='.';
                }
            }
        }
        vi ans;
        int dist;
        for(auto [x,y] : girls)
        {
            dist=1000;
            memset(visited,0,sizeof visited);
            queue<pii> q;
            q.push({x,y});
            visited[x][y]=1;
            int temp=0;
            while(!q.empty())
            {
                auto [a,b] = q.front();
                // cout<<a<<" "<<b<<" "<<dist<<endl;
                q.pop();
                
                if(grid[a][b]=='h')
                {
                    // dist=min(dist,temp);
                    break;
                }
                for(int i=0;i<4;i++)
                {
                    int nx=a+dx[i];
                    int ny=b+dy[i];
                    if(nx>=0 and nx<row and ny>=0 and ny<col and !visited[nx][ny])
                    {
                        visited[nx][ny]=1;
                        if(grid[nx][ny]=='.')
                            q.push({nx,ny});
                    }
                }
                temp++;
            }
            dist=min(dist,temp);
            ans.pb(dist);
        }
        cout << "Case " << c << ": ";
        for(auto x : ans)
            cout << x << " ";
        cout << endl;
    }

    return 0;
}
