////////////////////////////////////////////////////////////////////////////////////////////
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define be begin()
#define en end()
#define rb rbegin()
#define re rend()
#define all(x) (x).begin(), (x).end()
#define out cout << setprecision(20)

typedef vector<int> vi;
typedef vector<ll> vll;
typedef set<int> si;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MOD = 1e9 + 7;
const int INF = 1e9;

int failure[1000000];

void build(vector<int> pat, int m)
{
    failure[0] = failure[1] = 0;

    for (int i = 2; i <= m; i++)
    {
        int j = failure[i - 1];
        while (true)
        {
            if (pat[j] == pat[i - 1])
            {
                failure[i] = j + 1;
                break;
            }
            if (j == 0)
            {
                failure[i] = 0;
                break;
            }
            j = failure[j];
        }
    }
}

int kmp(vector<int> text, vector<int> pat, int n, int m)
{
    int cnt = 0;
    build(pat, m);

    int i, j;
    i = j = 0;

    while (true)
    {
        if (j == n)
        {
            return cnt;
        }
        if (text[j] == pat[i])
        {
            i++;
            j++;
            if (i == m)
            {
                i = failure[i];
                cnt++;
            }
        }
        else
        {
            if (i == 0)
                j++;
            else
                i = failure[i];
        }
    }
    return cnt;
}

int main(int argc, char *argv[])
{
    if (argc == 2 or argc == 3)
        freopen(argv[1], "r", stdin);
    if (argc == 3)
        freopen(argv[2], "w", stdout);
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    vi a, b;
    int x;
    cin >> x;
    for (int i = 1, y; i < n; i++)
    {
        cin >> y;
        a.pb(x - y);
        x = y;
    }
    cin >> x;
    for (int i = 1, y; i < m; i++)
    {
        cin >> y;
        b.pb(x - y);
        x = y;
    }
    if(m==1)
    {
        cout<<n<<endl;
    }
    else
    {
        cout<<kmp(a,b,n-1,m-1)<<endl;
    }
    return 0;
}
