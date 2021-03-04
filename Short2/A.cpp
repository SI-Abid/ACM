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

typedef vector<int> vi;
typedef vector<ll> vll;
typedef set<int> si;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MOD = 1e9 + 7;
const int INF = 1e9;
int dx[]={0,1,0,1};
int dy[]={0,0,1,1};

int main(int argc, char* argv[])
{
    if(argc == 2 or argc == 3) freopen(argv[1], "r", stdin);
    if(argc == 3) freopen(argv[2], "w", stdout);
    ios::sync_with_stdio(false);

    int h, w;
    cin>>h>>w;
    char img[h][w];
    for(int i=0; i<h; i++)
        for(int j=0; j<w; j++)
            cin>>img[i][j];
    
    if(h<2 || w<2)
    {
        puts("0");
        return 0;
    }
    int cnt=0;
    for(int i=0; i<h-1; i++)
        for(int j=0; j<w-1; j++)
        {
            string samp="";
            for(int t=0; t<4; t++)
            {
                samp+=img[i+dx[t]][j+dy[t]];
            }
            sort(all(samp));
            if(samp=="acef")
                cnt++;
        }
    cout<<cnt<<endl;
    return 0;
}
