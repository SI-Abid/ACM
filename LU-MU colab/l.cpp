#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 1e5;

vector<int> G[N];
int vis[N], Parent[N];
int cnt=0;
vector<int> counter;
void dfs(int u, int par)
{
    // cout<<u<<" -> ";
    vis[u] = 1;
    Parent[u] = par;
    for (auto v : G[u])
    {
        if (!vis[v])
        {
            cnt++;
            dfs(v, u);
        }
    }
    counter.push_back(cnt);
    // cout<<endl<<cnt<<endl;
    cnt--;
}

int main()
{

    int n, m, st;
    cin >> n >>st;
    m=n-1;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    // cin >> st;

    dfs(st, -1);
    cout<< *max_element(counter.begin(), counter.end())+1 <<endl;
    return 0;
}