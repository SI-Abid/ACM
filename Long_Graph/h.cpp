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
#define pcase(x) cout << "Case " << x << ": ";
void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) { cerr << *it << " = " << a << endl; err(++it, args...); }

typedef vector<int> vi;
typedef vector<ll> vll;
typedef set<int> si;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<pair<int, int>> vpii;

const int MOD = 1e9 + 7;
const int INF = 1e9;

int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};

char grid[200][200];
bool visited[200][200];
int distF[200][200];
int distJ[200][200];
// int parent[200][200];

int main(int argc, char* argv[])
{
    if(argc == 2 or argc == 3) freopen(argv[1], "r", stdin);
    if(argc == 3) freopen(argv[2], "w", stdout);
    ios::sync_with_stdio(false);

    int t;
    cin>>t;
    rep(tc,1,t+1)
    {
        int row,col;
        cin>>row>>col;
        pii J;
        vpii F;
        rep(i,0,row)
            rep(j,0,col)
            {
                cin>>grid[i][j];
                if(grid[i][j] == 'J')
                    J = {i,j};
                else if(grid[i][j] == 'F')
                    F.pb({i,j});
            }
        

        memset(visited,false,sizeof visited);
        queue<pii> q;
        for(auto f:F)
        {
            q.push(f);
            visited[f.F][f.S] = true;
            distF[f.F][f.S] = 0;
        }
        while(!q.empty())
        {
            auto [i,j] = q.front();
            q.pop();
            for(int k=0; k<4; k++)
            {
                int nx = i+dx[k];
                int ny = j+dy[k];
                if(nx>=0 and nx<row and ny>=0 and ny<col and !visited[nx][ny] and grid[nx][ny]!='#')
                {
                    visited[nx][ny] = true;
                    distF[nx][ny] = distF[i][j]+1;
                    // parent[nx][ny] = {i,j};
                    q.push({nx,ny});
                }
            }
        }
        
        int ans = -1;
        bool escape = false;
        memset(visited,false,sizeof visited);
        q.push(J);
        visited[J.F][J.S] = true;
        distJ[J.F][J.S] = 0;
        while(!q.empty() and !escape)
        {
            auto [i,j] = q.front();
            q.pop();
            for(int k=0; k<4; k++)
            {
                int nx = i+dx[k];
                int ny = j+dy[k];
                if(nx<0 or nx>=row or ny<0 or ny>=col)
                {
                    ans=distJ[i][j]+1;
                    escape = true;
                    break;
                }
                if(nx>=0 and nx<row and ny>=0 and ny<col and !visited[nx][ny] and grid[nx][ny]!='#')
                {
                    visited[nx][ny] = true;
                    if(distF[nx][ny]>distJ[i][j]+1)
                    {
                        distJ[nx][ny] = distJ[i][j]+1;
                        // parent[nx][ny] = {i,j};
                        q.push({nx,ny});
                    }
                }
            }
        }
        pcase(tc);
        if(ans==-1)
            cout<<"IMPOSSIBLE"<<endl;
        else
            cout<<ans<<endl;
    }

    return 0;
}
