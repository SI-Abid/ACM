// binary index tree
#include<bits/stdc++.h>
using namespace std;

struct Node
{
    bool val, lazy;
    Node *left, *right;
    Node()
    {
        lazy = 0;
        left = right = NULL;
    }
    ~Node()
    {
        delete left;
        delete right;
    }
};

void build(Node *root, int l, int r, string &s)
{
    if (l == r)
    {
        root->val = s[l-1] - '0';
        return;
    }
    int mid = (l + r) / 2;
    root->left = new Node();
    root->right = new Node();
    build(root->left, l, mid, s);
    build(root->right, mid + 1, r, s);
    root->val = root->left->val ^ root->right->val;
}

void update(Node *root, int l, int r, int pos_i, int pos_j)
{
    // outside the range
    if (pos_i > r or pos_j < l)
        return;
    // inside the range
    if (pos_i <= l and pos_j >= r)
    {
        root->lazy ^= 1;
        return;
    }
    int mid = (l + r) / 2;
    update(root->left, l, mid, pos_i, pos_j);
    update(root->right, mid + 1, r, pos_i, pos_j);
    root->val = root->left->val ^ root->right->val;
}

bool query(Node *root, int l, int r, int q, int carry=0)
{
    if (l == r)
        return root->val ^ carry ^ root->lazy;
    int mid = (l + r) / 2;
    if (q <= mid)
        return query(root->left, l, mid, q, root->lazy ^ carry);
    else
        return query(root->right, mid + 1, r, q, root->lazy ^ carry);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;cin>>t;
    int tc = 0;
    while(t--)
    {
        cout<< "Case " << ++tc << ":\n";
        string s;
        cin>>s;
        int n = s.length();
        Node *root = new Node();
        build(root, 1, n, s);
        int q;cin>>q;
        while(q--)
        {
            char type;cin>>type;
            if(type=='I')
            {
                int i,j;
                cin>>i>>j;
                update(root, 1, n, i, j);
            }
            else if(type=='Q')
            {
                int i;
                cin>>i;
                cout<<query(root, 1, n, i)<<endl;
            }
        }
    }
    return 0;
}