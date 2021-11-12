//counting cell
#include "bits/stdc++.h"
using namespace std;
#define uint unsigned int

bool visited[101][101]={false};
vector <string> v;
int dx[] = {1, 0, -1, 0, -1, 1, -1, 1};
int dy[] = {0, 1, 0, -1, -1, -1, 1, 1};
int m, n, cnt;

void grid(int a, int b)
{
	visited[a][b] = true;
	int x, y;
	for(int c=0; c<8; c++)
	{
		x = a+dx[c];
		y = b+dy[c];
		if(x>=0 && x<m && y>=0 && y<n && !visited[x][y])
		{
			// visited[x][y]=true;
			if(v[x][y]=='1')
            {
                cnt++;
				grid(x, y);
            }
		}
	}
	
}

int main()
{
	int t;
    cin>>t;
    cin.ignore();
    while(t--)
    {
        string s;
        while(cin>>s)
        {
            v.push_back(s);
        }

        m=v.size();
        n=v[0].size();
        memset(visited, false, sizeof(visited));
        int count=0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if(!visited[i][j])
                {
                    visited[i][j]=true;
                    if(v[i][j]=='1')
                    {
                        cnt=1;
                        grid(i,j);
                        count=max(cnt,count);
                    }
                }
            }
            
        }
        cout<<count<<endl<<endl;
    }
	return 0;
}
