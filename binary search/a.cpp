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
#define rb rbegin()
#define re rend()
#define all(x) (x).begin(),(x).end()
#define out cout<<setprecision(20)

typedef vector<int> vi;
typedef vector<ll> vll;
typedef set<int> si;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MOD = 1e9 + 7;
const int INF = 1e9;

vi v(10000);

int find(int l, int r, int x)
{
    if(r>=l)
    {
        int mid=(l+r) /2; 

        if(v[mid]==x) 
        {
            return mid;
        }
        if(v[mid]>x)    
        {
            return find(l, mid-1, x); 
        }
        else
           return find(mid+1, r, x);
    }
    return -1;
}

int main(int argc, char* argv[])
{
    if(argc == 2 or argc == 3) freopen(argv[1], "r", stdin);
    if(argc == 3) freopen(argv[2], "w", stdout);
    ios::sync_with_stdio(false);

    int n,q,tc=1;
    while(cin>>n>>q)
    {
        if(n==0 or q==0)
            break;
        
        cout<<"CASE# "<<tc++<<":"<<endl;

        v.clear();
        for (int i = 0; i < n; i++)
        {
            cin>>v[i];
        }

        sort(all(v));

        while(q--)
        {
            int x;
            cin>>x;
            int pos=find(0,n-1,x);
            if(pos==-1)
            {
                cout<<x<<" not found"<<endl;
            }
            else
                cout<<x<<" found at "<<pos+1<<endl;
        }
        
        
    }    
    
    return 0;
}
