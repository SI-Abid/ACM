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

#define d 31
#define mod 3803

int *hash_b;
int **hash_a;
int *mul;

// Function to return the modular inverse
// using Fermat's little theorem
int mi(int x)
{
    int p = mod - 2;
    int s = 1;
    while (p != 1)
    {
        if (p % 2 == 1)
            s = (s * x) % mod;
        x = (x * x) % mod;
        p /= 2;
    }

    return (s * x) % mod;
}

// Function to generate hash
void genHash(vector<string>a, vector<string>b)
{
    // To store prefix-sum
    // of rolling hash
    hash_a = new int[a.size()];
    for(int i=0;i<a.size();i++)
        hash_a[i] = new int[a[0].size()];

    // Multiplier for different values of i
    mul = new int[a.size()];

    hash_b = new int[b.size()];

    // Generating hash value for string b
    for(int k=0;k<b.size();k++)
        for (int i = b.size() - 1; i >= 0; i--)
            hash_b[k] = (hash_b[k] * d + (b[k][i] - 97)) % mod;

    // Generating prefix-sum of hash of a
    mul[0] = 1;
    hash_a[0] = (a[0] - 97) % mod;
    for(int k=0;k<a.size();k++)
        for (int i = 1; i < a[0].size(); i++)
        {
            mul[i] = (mul[i - 1] * d) % mod;
            hash_a[k][i] = (hash_a[k][i - 1] + mul[i] * (a[k][i] - 97)) % mod;
        }
}

void init()
{
    hash_a = NULL;
    
    mul = NULL;
    hash_b = 0;
}

bool checkEqual(int i, int len_a, int len_b)
{
    // To store hash of required
    // sub-string of A
    int x;

    // If i = 0 then
    // requires hash value
    if (i == 0)
        x = hash_a[len_b - 1];

    // Required hash if i != 0
    else
    {
        x = (hash_a[i + len_b - 1] - hash_a[i - 1] + 2 * mod) % mod;
        x = (x * mi(mul[i])) % mod;
    }

    // Comparing hash with hash of B
    if (x == hash_b)
        return true;

    return false;
}

void solve()
{
    init();

    string a = "abcbcdcdeabbc";
    string b = "ab";

    int n, m;
    n = a.size();
    m = b.size();

    genHash(a, b);
    int cnt = 0;
    for (int i = 0; i <= n - m; i++)
    {
        if (checkEqual(i, n, m))
            cnt++;
    }
    printf("Total %d matches found\n", cnt);
}

int main(int argc, char *argv[])
{
    if (argc == 2 or argc == 3)
        freopen(argv[1], "r", stdin);
    if (argc == 3)
        freopen(argv[2], "w", stdout);
    ios::sync_with_stdio(false);

    // freopen("in", "r", stdin);

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}