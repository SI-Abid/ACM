#include <bits/stdc++.h>
using namespace std;

signed main()
{
    int _;
    cin >> _;
    for (int tc = 1; tc <= _; tc++)
    {
        // printf("Case %d: ",tc);

        int nodes;
        cin >> nodes;
        vector<vector<int>> adj(nodes + 1);
        for (size_t i = 0; i < nodes; i++)
        {
            int node, child;
            cin >> node;
            cin.ignore();
            cin.ignore();
            cin >> child;
            cin.ignore();
            while (child--)
            {
                int x;
                cin >> x;
                adj[node].push_back(x);
            }
        }
        int timer = 0;
        vector<int> tin(nodes + 1), low(nodes + 1);
        vector<bool> vis(nodes + 1);
        vector<pair<int, int>> bridges;
        function<void(int, int)> dfs = [&](int node, int par)
        {
            vis[node] = true;
            tin[node] = low[node] = timer++;
            for (auto child : adj[node])
            {
                if (child == par)
                    continue;
                if (vis[child])
                {
                    low[node] = min(low[node], tin[child]);
                }
                else
                {
                    dfs(child, node);
                    low[node] = min(low[node], low[child]);
                    if (low[child] > tin[node])
                    {
                        if (node < child)
                            bridges.push_back({node, child});
                        else
                            bridges.push_back({child, node});
                    }
                }
            }
        };
        for (int i = 1; i <= nodes; i++)
        {
            if (!vis[i])
            {
                dfs(i, -1);
            }
        }
        cout << "Case " << tc << ":" << endl;
        cout << bridges.size() << " critical links" << endl;
        sort(bridges.begin(), bridges.end());
        for (auto x : bridges)
        {
            cout << x.first << " - " << x.second << endl;
        }
    }
    return 0;
}