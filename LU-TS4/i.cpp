#include<bits/stdc++.h>
using namespace std;

//direction array for knight moves
int dx[] = {-2, -2, -1, -1, 1, 1, 2, 2};
int dy[] = {-1, 1, -2, 2, -2, 2, -1, 1};

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        char c;
        cin>>c;
        int m = c-'a'+1;
        int cnt = 0;
        for(int i=0; i<8; i++)
        {
            if(n+dx[i]<=8 && m+dy[i]<=8 && n+dx[i]>=1 && m+dy[i]>=1)
                cnt++;
        
        }
        cout<<cnt<<endl;
    }
    return 0;
}