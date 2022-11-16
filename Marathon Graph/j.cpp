#include<bits/stdc++.h>
using namespace std;

signed main()
{
    int n,m;
    cin>>n>>m;
    vector<string> grid(n);
    for (int i = 0; i < n; i++)
    {
        cin>>grid[i];
    }
    int sx,sy,ex,ey;
    cin>>sx>>sy>>ex>>ey;
    sx--,sy--,ex--,ey--;
    queue<pair<int,int>> q;
    q.push({sx,sy});
    int dx[4]={1,-1,0,0};
    int dy[4]={0,0,1,-1};
    bool flag=false;
    while(!q.empty())
    {
        auto [x,y]=q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(nx>=0 && nx<n && ny>=0 && ny<m)
            {
                if(grid[nx][ny]=='.')
                {
                    grid[nx][ny]='X';
                    q.push({nx,ny});
                }
                else if(nx==ex && ny==ey)
                {
                    flag=true;
                }
            }
        }
    }
    if(flag)
    {
        cout<<"YES"<<endl;
    }
    else
    {
        cout<<"NO"<<endl;
    }
    return 0;
}