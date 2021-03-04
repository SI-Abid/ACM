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

int main(int argc, char* argv[])
{
    if(argc == 2 or argc == 3) freopen(argv[1], "r", stdin);
    if(argc == 3) freopen(argv[2], "w", stdout);
    ios::sync_with_stdio(false);

    int t;
    cin>>t;
    deque<int> dq;
    for(int tt=1; tt<=t; tt++)
    {
        string s;
        int n, m, p;
        cin>>n>>m;
        cout<<"Case "<<tt<<":\n";
        while(m--)
        {
            cin>>s;
            if(s=="pushLeft" || s=="pushRight")
            {
                cin>>p;
                if(dq.size()<n)
                {
                    if(s=="pushLeft")
                    {
                        cout<<"Pushed in left: "<<p<<endl;
                        dq.push_front(p);
                    }
                    else
                    {
                        cout<<"Pushed in right: "<<p<<endl;
                        dq.push_back(p);
                    }
                }
                else
                {
                    cout<<"The queue is full\n";
                }
            }
            if(s=="popLeft" || s=="popRight") 
            {
                if(dq.empty())
                {
                    cout<<"The queue is empty\n";
                }
                else
                {
                    if(s=="popLeft")
                    {
                        cout<<"Popped from left: "<<dq.front()<<endl;
                        dq.pop_front();
                    }
                    else
                    {
                        cout<<"Popped from right: "<<dq.back()<<endl;
                        dq.pop_back();
                    }
                }
            }
        }
        dq.clear();
    }
    return 0;
}
