// AUTHOR: Kamonasish Roy
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // freopen("in.txt", "r", stdin);
    int n, m;
    cin >> n >> m;
    vector<int> dp(100000, 1e9);
    dp[0] = 0;
    vector<pair<int, int>> vec;
    for (int i = 1; i <= m; i++)
    {
        int x, y;
        cin >> x >> y;
        vec.push_back({x, y});
    }
    sort(vec.begin(), vec.end());
    for (int i = 1; i <= m; i++)
    {
        int len = vec[i - 1].first;
        int cost = vec[i - 1].second;
        for (int j = 0; j <= n; j++)
        {
            if (j < len)
            {
                dp[j] = min(dp[j], cost);
            }
            else
            {
                dp[j] = min(dp[j], dp[j - len] + cost);
            }
        }
    }
    cout << dp[n] << "\n";

    return 0;
}
