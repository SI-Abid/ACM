#include<bits/stdc++.h>
using namespace std;

struct Node 
{
    int cnt;
    Node *next[2];
    Node()
    {
        cnt = 0;
        next[0] = next[1] = NULL;
    }
    void insert(string s)
    {
        int len = s.length();
        Node *cur = this;
        for(int i = 0; i < len; i++)
        {
            int idx = s[i] - '0';
            if(cur->next[idx] == NULL)
            {
                cur->next[idx] = new Node();
            }
            cur = cur->next[idx];
            cur->cnt++;
        }
    }
};

void dfs(Node *root, int &ans, int lvl)
{
    if(root == NULL)
        return;

    ans = max(ans, lvl*root->cnt);

    for(int i = 0; i < 2; i++)
    {
        dfs(root->next[i], ans, lvl + 1);
    }
}

int main(int argc, char const *argv[])
{
    if(argc >= 2 )
    {
        freopen(argv[1], "r", stdin);
        if(argc == 3) freopen(argv[2], "w", stdout);
    }

    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        Node *root = new Node();
        string s;
        for(int i = 0; i < n; i++)
        {
            cin>>s;
            root->insert(s);
        }
        int ans = 0;
        int lvl = 0;
        dfs(root, ans, lvl);
        cout<<ans<<endl;
    }
    return 0;
}
