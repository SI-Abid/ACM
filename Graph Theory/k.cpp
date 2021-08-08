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

const int row=35, col=85;
bool vis[row][col];
char v[row][col];

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

void grid(int a, int b, int m, int n)
{
	vis[a][b] = true;
	int x, y;
	for(int c=0; c<4; c++)
	{
		x = a+dx[c];
		y = b+dy[c];
		if(x>=0 && x<m && y>=0 && y<n && !vis[x][y])
		{
			if(v[x][y]==' ')
				grid(x, y, m, n);
		}
	}
	
}

int main(int argc, char* argv[])
{
    if(argc == 2 or argc == 3) freopen(argv[1], "r", stdin);
    if(argc == 3) freopen(argv[2], "w", stdout);
    ios::sync_with_stdio(false);

    int t;
    cin>>t;
    cin.ignore();
    while(t--)
    {
        vi lens;
        string s;
        pair<int, int> pos;
        memset(v, '0', sizeof(v));
        int i=0;
        while(getline(cin, s))
        {
            lens.push_back(s.size());
            for(int k=0; k<s.size(); k++)
            {
                v[i][k] = s[k];
                if(s[k]=='*')
                {
                    pos = make_pair(i, k);
                }
            }
            if(s[0]=='_')   break;
            i++;
        }
        // cout<<i<<endl;
        memset(vis, 0, sizeof(vis));
        // for(int k=0; k<i; k++)
        // {
        //     Could not see the underscore printed in terminal [spent a whole day after this]
        //     printf("%s\n", v[k]);    
        // }
        grid(pos.F, pos.S, i, col);

        for(int k=0; k<lens.size(); k++)
        {
            for(int j=0; j<lens[k]; j++)
            {
                if(vis[k][j])
                {
                    cout<<"#";
                }
                else
                {
                    cout<<v[k][j];
                }
            }
            cout<<endl;
        }
        
    }
    
    return 0;
}
