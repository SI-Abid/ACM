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
#define all(x) (x).begin(),(x).end()
#define out cout<<setprecision(20)

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

    string s;
    cin>>s;
    int cnt=0;
    stack<char> st;
    for(char c:s)
    {
        switch(c)
        {
            case '<':
            case '{':
            case '(':
            case '[':
                st.push(c);
                break;
            case '>':
            case '}':
            case ')':
            case ']':
                if(!st.empty())
                {
                    // cout<<st.top()<<" "<<c<<endl;
                    if(st.top()=='<' and c=='>');
                    else if(st.top()=='{' and c=='}');
                    else if(st.top()=='(' and c==')');
                    else if(st.top()=='[' and c==']');
                    else
                        cnt++;
                    st.pop();
                }
                else
                {
                    cout<<"Impossible"<<endl;
                    return 0;
                }
                break;
        }
    }
    if(st.empty())
        cout<<cnt<<endl;
    else
        cout<<"Impossible"<<endl;
    return 0;
}
