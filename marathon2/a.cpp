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

priority_queue<pair<long long int, int>> pq;
vector<pair<int, int>> x[100005];
long long int dis[100005];
int par[100005];
vector<int> path;

void pave(int n)
{
    if(n>0 && par[n] == -1)
        return;
    if (par[n] > 0)
        pave(par[n]);
    path.push_back(n);
}
void dijkstra(int src)
{
    for (int i = 1; i < 100005; i++)
    {
        par[i] = -1;
        dis[i] = 1e18;
    }
    dis[src] = 0;
    par[src] = 0;
    pq.push({-dis[src], src});
    while (!pq.empty())
    {
        int currentNode = pq.top().second;
        long long int currentCost = -pq.top().first;
        pq.pop();
        for (auto to : x[currentNode])
        {
            int node = to.first;
            long long int currentDis = currentCost + to.second;
            if (currentDis < dis[node])
            {
                dis[node] = currentDis;
                par[node] = currentNode;
                pq.push({-dis[node], node});
            }
        }
    }
}
void clear()
{
    for (int i = 0; i < 100005; i++)
    {
        x[i].clear();
    }
    path.clear();
}
int main(int argc, char const *argv[])
{
    if(argc == 2 or argc == 3) freopen(argv[1], "r", stdin);
    if(argc == 3) freopen(argv[2], "w", stdout);
    ios::sync_with_stdio(false);

    int NI, tc=1;
    while(cin>>NI)
    {
        if(NI==0)
            break;
        clear();
        for(int i=1;i<=NI;i++)
        {
            int ns;
            cin>>ns;
            while(ns-->0)
            {
                int y,cost;
                cin>>y>>cost;
                x[i].push_back({y,cost});
            }
        }

        int src,dest;
        cin>>src>>dest;
        dijkstra(src);
        pave(dest);
        cout<<"Case "<<tc++<<": Path =";
        for(auto i:path)
            cout<<" "<<i;
        cout<<"; "<<dis[dest]<<" second delay"<<endl;

    }
    
    return 0;
}