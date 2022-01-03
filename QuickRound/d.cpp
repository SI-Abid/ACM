#include<bits/stdc++.h>
using namespace std;

int dx[]={0,0,1,-1,1,1,-1,-1};
int dy[]={1,-1,0,0,1,-1,1,-1};

int main()
{
    int h,w;
    cin>>h>>w;
    char grid[h][w];
    int score[h][w];
    memset(score,0,sizeof score);
    for(int i=0;i<h;i++)
    {
        for(int j=0;j<w;j++)
        {
            cin>>grid[i][j];
        }
    }
    for(int i=0;i<h;i++)
    {
        for(int j=0;j<w;j++)
        {
            if(grid[i][j]=='.')
            {
                for(int k=0;k<8;k++)
                {
                    int nx=i+dx[k];
                    int ny=j+dy[k];
                    if(nx>=0 and nx<h and ny>=0 and ny<w and grid[nx][ny]=='#')
                    {
                        score[i][j]++;
                    }
                }
            }
        }
    }
    for(int i=0;i<h;i++)
    {
        for(int j=0;j<w;j++)
        {
            if(grid[i][j]=='.')
            {
                if(score[i][j])
                    cout<<score[i][j];
                else
                    cout<<'0';
            }
            else
            {
                cout<<"#";
            }
        }
        cout<<endl;
    }
    return 0;
}