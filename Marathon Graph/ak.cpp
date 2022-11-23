#include<bits/stdc++.h>
using namespace std;

signed main()
{
    int _;
    cin>>_;
    for(int tc=1;tc<=_;tc++)
    {
        // printf("Case %d: ",tc);
    
        int n,m;
        cin>>n>>m;
        vector<string> grid(n);
        for(auto &x:grid)
            cin>>x;
        int hx,hy;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]=='h')
                {
                    hx=i;
                    hy=j;
                }
            }
        }
        static int dx[]={0,0,1,-1};
        static int dy[]={1,-1,0,0};
        vector<vector<int>> dist(n,vector<int>(m,INT_MAX));
        queue<pair<int,int>> q;
        q.push({hx,hy});
        dist[hx][hy]=0;
        int ans=0;
        while(!q.empty())
        {
            auto [x,y]=q.front();
            q.pop();
            for(int i=0;i<4;i++)
            {
                int nx=x+dx[i];
                int ny=y+dy[i];
                if(nx>=0 && nx<n && ny>=0 && ny<m && grid[nx][ny]!='m' && grid[nx][ny]!='#' && dist[nx][ny]==INT_MAX)
                {
                    dist[nx][ny]=dist[x][y]+1;
                    if(grid[nx][ny]=='a' || grid[nx][ny]=='b' || grid[nx][ny]=='c')
                        ans=max(ans,dist[nx][ny]);
                    q.push({nx,ny});
                }
            }
        }
        cout<<"Case "<<tc<<": "<<ans<<endl;
    }
    return 0;
}