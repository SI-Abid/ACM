#include <iostream>
#include <string>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <list>
#include <set>
#include <cmath>
#include <cstring>

#include <stdio.h>
#include <string.h>
#include <sstream>
#include <stdlib.h>
#include <vector>
#include <iomanip>
#include <ctime>

using namespace std;

struct Node {
    int cost;
    vector<int>edge;
};
const int INF = 1e9;
vector<Node>lift,flr;
int dis[105];
priority_queue< pair <int, int>> pq;

void clear(int n) 
{
    lift.clear();
    lift.resize(n);
    flr.clear();
    flr.resize(100);
}

int main(int argc, char const *argv[])
{
    if (argc == 2 or argc == 3)
        freopen(argv[1], "r", stdin);
    if (argc == 3)
        freopen(argv[2], "w", stdout);
    ios::sync_with_stdio(false);

    int n, k, tc=1;
    
    while(cin>>n>>k)
    {
        clear(n);
        //cout<<n<<" "<<k<<endl;
        //cout<<"Scenario #"<<tc++<<":"<<endl;
        for(int i=0;i<n;i++)
        {
            cin>>lift[i].cost;
            //cout<<lift[i].cost<<" ";
        }
        //cout<<endl;
        getchar();getchar();
        for(int i=0;i<n;i++)
        {
//https://stackoverflow.com/questions/21594533/c-extract-int-from-string-using-stringstream
            string s, t;
            
            getline(cin,s);
            

            stringstream ss(s);
            int x;//cout<<"accessible floor for lift: "<<i<<" "<<s<<endl;
            while(getline(ss,t,' '))
            {
                if(stringstream(t)>>x)
                {
                    lift[i].edge.push_back(x);
                    flr[x].edge.push_back(i);
                }
            }
        }
        for(int i=0;i<lift.size();i++)
        {
            cout<<"lift: "<<i<<endl;
            for(int j=0;j<lift[i].edge.size();j++)
            {
                cout<<lift[i].edge[j]<<" ";
            }
            cout<<endl;
        }
        for(int i=0;i<100;i++)
        {
            if(flr[i].edge.size()==0)
                continue;
            cout<<"floor: "<<i<<endl;
            for(int j=0;j<flr[i].edge.size();j++)
            {
                cout<<flr[i].edge[j]<<" ";
            }
            cout<<endl;
        }
        for(int i=1;i<=100;i++)
        {
            dis[i]=INF;
        }
        dis[0]=0;
        for(int i=0;i<100;i++)
        {
            if(flr[i].cost==INF)
                continue;
            for(int j=0;j<flr[i].edge.size();j++)
            {
                int l=flr[i].edge[j];
                for(int k=0;k<lift[l].edge.size();k++)
                {
                    int f=lift[l].edge[k];
                    if(dis[f]>dis[i]+lift[l].cost*(abs(i-f)+1))
                    {
                        dis[f]=dis[i]+lift[l].cost*(abs(i-f)+1);
                    }
                }
            }
        }
        cout<<"Case "<<tc++<<": "<<dis[k]<<endl;
        // for(int i=1;i<=100;i++)
        // {
        //     if(dis[i]!=INF)
        //     {
        //         cout <<"flr "<< i << " = " << dis[i] << endl;
        //     }
        // }
        if(dis[k]==INF)
        {
            cout<<"Not possible"<<endl;
        }
        else 
            cout<<dis[k]<<endl;
    }
    return 0;
}
