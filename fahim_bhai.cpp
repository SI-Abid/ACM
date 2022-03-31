#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
struct Node
{
    bool end;
    Node *next[2];
    Node()
    {
        end = false;
        next[0] = next[1] = NULL;
    }
    void insert(string s)
    {
        int len = s.length();
        Node *cur = this;
        for (int i = 0; i < len; i++)
        {
            int idx = s[i] - '0';
            if (cur->next[idx] == NULL)
            {
                cur->next[idx] = new Node();
            }
            cur = cur->next[idx];
        }
        cur->end = true;
    }
    void getMax(string &s, int idx, int &ans, Node *cur)
    {
        if (idx == s.length())
        {
            return;
        }
        int idx1 = s[idx] - '0';
        idx1 ^= 1; // invert the bit
        if (cur->next[idx1] == NULL)
        {
            idx1 ^= 1;
        }
        ans <<= 1;
        ans += idx1;
        getMax(s, idx + 1, ans, cur->next[idx1]);
    }
    void getMin(string &s, int idx, int &ans, Node *cur)
    {
        if (idx == s.length())
        {
            return;
        }
        int idx1 = s[idx] - '0';
        if (cur->next[idx1] == NULL)
        {
            idx1 ^= 1;
        }
        ans <<= 1;
        ans += idx1;
        getMin(s, idx + 1, ans, cur->next[idx1]);
    }
    void del()
    {
        for (int i = 0; i < 2; i++)
        {
            if (next[i] != NULL)
            {
                next[i]->del();
            }
        }
        delete this;
    }
};

string toBin(int n)
{
    return bitset<32>(n).to_string();
}

void solve()
{

    Node *root = new Node();
    root->insert(toBin((0)));
    int n, ma = 0, mi=INT_MAX;
    cin >> n;
    for (int i = 0, a, x = 0; i < n; i++)
    {
        cin >> a;
        x ^= a;
        // cout<<x<<endl;
        Node *cur = root;
        int ans=0;
        auto p = toBin(x);
        cur->getMax(p, 0, ans, cur);
        ans ^= x;
        ma = max(ma, ans);
        cur=root;
        ans=0;
        cur->getMin(p,0,ans,cur);
        ans^=x;
        // cout<<x<<' '<<ans<<endl;
        mi = min(mi, ans);
        cur = root;
        cur->insert(p);

    }
    root->del();
    cout << ma << " "<<mi<<endl;
}

int main(int argc, char const **argv)
{
    if (argc >= 2)
        freopen(argv[1], "r", stdin);
    if (argc >= 3)
        freopen(argv[2], "w", stdout);

    int t;
    cin>>t;
    for (int i = 0; i < t;)
    {
        cout<<"Case "<<++i<<": ";
        solve();
    }
    
    return 0;
}