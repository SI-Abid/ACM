/*One touch and i IGNITE*/
#include<iostream>
#include<queue>
using namespace std;
#define To_Infinity_And_Beyond ios_base::sync_with_stdio(false),cin.tie(0)
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int N = 1e3 + 5;
int tc, n, m, casee = 1, a[N][N];
ll dis[N][N];

int fx[] = {1, -1, 0, 0};
int fy[] = {0, 0, 1, -1};

struct R {
    ll cost;
    int sx, sy;
    bool operator<(R a)const {
        return cost > a.cost;
    }
};

bool valid(int tx, int ty) {
    return (tx >= 1 && ty >= 1 && tx <= n && ty <= m);
}

void djk() {
    priority_queue < R > pq;
    pq.push({a[1][1], 1, 1});
    dis[1][1] = a[1][1];
    while(pq.size()) {
        ll cost = pq.top().cost;
        int sx = pq.top().sx, sy = pq.top().sy;
        pq.pop();
        for(int i = 0; i < 4; i++) {
            int tx = sx + fx[i], ty = sy + fy[i];
            if(!valid(tx, ty))continue;
            ll newCost = cost + a[tx][ty];
            if(dis[tx][ty] > newCost) {
                dis[tx][ty] = newCost;
                pq.push({newCost, tx, ty});
            }
        }
    }

}

int main() {
#ifdef cloud_007
    freopen("in.txt", "r", stdin);
#endif // cloud_007
    To_Infinity_And_Beyond;
    cin >> tc;
    while(tc--) {
        cin >> n >> m;
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                cin >> a[i][j];
                dis[i][j] = 1e18;
            }
        }
        djk();
        cout << dis[n][m] << endl;
    }


    return 0;
}