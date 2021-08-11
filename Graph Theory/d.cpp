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

bool grid[1005][1005];
bool vis[1005][1005];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int main(int argc, char* argv[])
{
    if(argc == 2 or argc == 3) freopen(argv[1], "r", stdin);
    if(argc == 3) freopen(argv[2], "w", stdout);
    ios::sync_with_stdio(false);

    int r,c;
    while(cin >> r >> c)
    {
        if(r == 0 and c == 0) break;
        memset(grid, false, sizeof grid);   
        memset(vis, false, sizeof vis);

        int br; cin>>br;
        while(br--)
        {
            int row; cin>>row;
            int bc; cin>>bc;
            int col;
            while(bc--)
            {
                cin>>col;
                grid[row][col] = true;     // mark as bomb
            }
        }

        int sx, sy, ex, ey;
        cin >> sx >> sy >> ex >> ey;
        
        int dist = 0;
        int lvl[r+2][c+2];
        queue<pii> q;

        q.push(mp(sx, sy));
        lvl[sx][sy] = 0;
        vis[sx][sy] = true;

        while(!q.empty())
        {
            pii now = q.front();
            q.pop();

            if(now.F == ex && now.S == ey)
            {
                break;
            }
            for(int i = 0; i < 4; i++)
            {
                int nx = now.F + dx[i];
                int ny = now.S + dy[i];

                if(nx >= 0 && nx < r && ny >= 0 && ny < c && !grid[nx][ny] && !vis[nx][ny])
                {
                    vis[nx][ny] = true;
                    q.push(mp(nx, ny));
                    lvl[nx][ny] = lvl[now.F][now.S] + 1;
                }
            }
        }

        cout << lvl[ex][ey] << endl;

        q.empty();
    }
    
    return 0;
}
