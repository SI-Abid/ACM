#include "bits/stdc++.h"
using namespace std;

#define ll long long
#define ull unsigned long long
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define be begin()
#define en end()
#define all(x) (x).begin(),(x).end()
#define out cout<<setprecision(20)

typedef vector<int> vi;
typedef vector<ll> vll;
typedef set<int> si;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MOD = 1e9 + 7;
const int INF = 1e9;

const int size = 1000005;
int a[size];

void cubeArrayPosition()
{
    a[0]=0;
    a[1]=1;
    for(int i=2;i<size;i++)
    {
        a[i]=max(a[i-1],a[i-2])+1;
        for(int j=2;j<=100;j++)
        {
            int k = j*j*j;
            if(i%k==0)
            {
                a[i]=0;
                break;
            }
        }
    }
}

int main(int argc, char* argv[])
{
    if(argc == 2 or argc == 3) freopen(argv[1], "r", stdin);
    if(argc == 3) freopen(argv[2], "w", stdout);
    ios::sync_with_stdio(false);
    // start time
    // clock_t start = clock();
    cubeArrayPosition();
    // // end time
    // clock_t end = clock();
    // cout << "Time: " << ((double) (end - start) / CLOCKS_PER_SEC) << endl;
    int t;
    cin >> t;
    for(int i = 1; i <= t; i++)    
    {
        int n;
        cin >> n;
        if(a[n])
        {
            cout << "Case " << i << ": " << a[n] << endl;
        }        
        else
        {
            cout << "Case " << i << ": Not Cube Free" << endl;
        }
    }
    return 0;
}
