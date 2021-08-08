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
#define all(x) (x).begin(), (x).end()
#define out cout << setprecision(20)

typedef vector<int> vi;
typedef vector<ll> vll;
typedef set<int> si;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MOD = 1e9 + 7;
const int INF = 1e9;

int cnt;
char grid[20][20] = {};
bool visited[20][20] = {};
int dx[] = {0, -1, 0, 1};
int dy[] = {-1, 0, 1, 0};

void dfs(int a, int b, int n, int m)
{
    visited[a][b] = true;
    int x, y;
    for (int k = 0; k < 4; k++)
    {
        x = a + dx[k];
        y = b + dy[k];
        if (x >= 0 && x < n && y >= 0 && y < m && !visited[x][y])
        {
            visited[x][y] = true;
            if (grid[x][y] == '.')
            {
                cnt++;
                dfs(x, y, n, m);
            }
        }
    }
}

void solve()
{
    int n, m;
    cin >> m >> n;
    memset(grid, '\0', 400);
    memset(visited, 0, 400);
    int rootx, rooty;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
            if (grid[i][j] == '@')
            {
                rootx = i;
                rooty = j;
            }
        }
    }

    cnt = 1;

    dfs(rootx, rooty, n, m);

    cout << cnt << endl;
}

int main(int argc, char *argv[])
{
    if (argc == 2 or argc == 3)
        freopen(argv[1], "r", stdin);
    if (argc == 3)
        freopen(argv[2], "w", stdout);
    ios::sync_with_stdio(false);

    int t, it = 1;
    for (cin >> t; t; t--)
    {
        cout << "Case " << it++ << ": ";
        solve();
    }

    return 0;
}