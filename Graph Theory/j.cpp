#include "bits/stdc++.h"
using namespace std;
#define uint unsigned int

bool visited[101][101]={false};
vector <string> v;
int dx[] = {1, 0, -1, 0, -1, 1, -1, 1};
int dy[] = {0, 1, 0, -1, -1, -1, 1, 1};
int m, n;

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
			visited[x][y]=true;
			if(v[x][y]=='@')
				grid(x, y);
		}
	}
	
}

int main()
{
	
	string s;
	while(true)
	{
		cin>>m>>n;
		if(m==0) break;
		v.clear();
		
		for (int i=0; i<m; i++)
		{
			cin>>s;
			v.push_back(s);
		}
		int count = 0;
		memset(visited, false, sizeof(visited));
		for(int i=0; i<m; i++)
		{
			for(int j=0; j<n; j++)
			{
				if(!visited[i][j])
				{
                    visited[i][j] = true;
                    if(v[i][j]=='@')
                    {
                        count++;
                        grid(i,j);
                    }
                }
			}
		}
		cout<<count<<endl;
	}
	return 0;
}
