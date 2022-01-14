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
pii parent[100][100];
int level[100][100];

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
        // vpii girls(3);
        int sx,sy;
        rep(i,0,row)
        {
            rep(j,0,col)
            {
                cin>>grid[i][j];
                if(grid[i][j] == 'h')
                    sx=i,sy=j;
            }
        }

        memset(visited,0,sizeof(visited));
        memset(parent,-1,sizeof(parent));
        memset(level,-1,sizeof(level));

        queue<pii> q;
        q.push({sx,sy});
        visited[sx][sy]=true;
        parent[sx][sy]={-1,-1};
        level[sx][sy]=0;
        int dist=1;

        while(!q.empty())
        {
            pii cur=q.front();
            q.pop();
            if(grid[cur.F][cur.S]=='a' or grid[cur.F][cur.S]=='b' or grid[cur.F][cur.S]=='c')
            {
                dist=max(dist,level[cur.F][cur.S]);
                // continue;
            }
            rep(i,0,4)
            {
                int nx=cur.F+dx[i], ny=cur.S+dy[i];
                if(nx>=0 and nx<row and ny>=0 and ny<col and !visited[nx][ny])
                {
                    visited[nx][ny]=true;
                    parent[nx][ny]={cur.F,cur.S};
                    level[nx][ny]=level[cur.F][cur.S]+1;
                    if(grid[nx][ny]!='#' and grid[nx][ny]!='m')
                        q.push({nx,ny});
                }
            }
        }/* 
        rep(i,0,row)
        {
            rep(j,0,col)
                // cout<<parent[i][j].F<<" "<<parent[i][j].S<<" | ";
                // cout<<level[i][j]<<" ";
            cout<<endl;
        } */
        cout << "Case " << c << ": "<< dist << endl;
        // for(auto x : ans)
        //     cout << x << " ";
        // cout << endl;
    }

    return 0;
}
