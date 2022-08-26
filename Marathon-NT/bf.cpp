#include<bits/stdc++.h>
using namespace std;

const int LIMIT = 1e8;
vector<vector<long long>> maps;

void init()
{
    maps.resize(LIMIT,vector<long long>(10,0));
    for(int i=1;i<LIMIT;i++)
    {
        for(int j=0;j<10;j++)
        {
            maps[i][j] = maps[i-1][j] + maps[i-1][(j+1)%10];
        }
        int tmp=i;
        while(tmp)
        {
            maps[i][tmp%10]++;
            tmp/=10;
        }
    }
}

int main(const int argc, const char **argv)
{
    if(argc>=2) freopen(argv[1],"r",stdin);
    if(argc==3) freopen(argv[2],"w",stdout);

    init();
    int a,b;
    // for(int i=100;i<110;i++)
    // {
    //     for(int j=0;j<10;j++)
    //         cout<<maps[i][j]<<" ";
    //     cout<<endl;
    // }
    while(cin>>a>>b)
    {
        if(a>b)
        {
            swap(a,b);
        }
        if(a+b==0) break;
        for(int i=0;i<10;i++)
        {
            cout<<maps[b][i]-maps[a-1][i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}