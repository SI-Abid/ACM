#include<bits/stdc++.h>
using namespace std;

struct node
{
    int val;
    node *left, *right;
    node(int x)
    {
        val = x;
        left = right = NULL;
    }
};

void build(node *root, int l, int r, vector<int> &s)
{
    if (l == r)
    {
        root->val = s[l];
        return;
    }
    int mid = (l + r) / 2;
    root->left = new node(0);
    root->right = new node(0);
    build(root->left, l, mid, s);
    build(root->right, mid + 1, r, s);
    root->val = root->left->val + root->right->val;
}

void update(node *root, int l, int r, int i, int val)
{
    if (l == r)
    {
        root->val += val == 0 ? -root->val : val;
        return;
    }
    int mid = (l + r) / 2;
    if (i <= mid)
        update(root->left, l, mid, i, val);
    else
        update(root->right, mid + 1, r, i, val);
    root->val = root->left->val + root->right->val;
}

int query(node *root, int l, int r, int i, int j)
{
    if (l > j || r < i)
        return 0;
    if (l >= i && r <= j)
        return root->val;
    int mid = (l + r) / 2;
    return query(root->left, l, mid, i, j) + query(root->right, mid + 1, r, i, j);
}

int main()
{
    int t;cin>>t;
    for (int tt = 0; tt < t; tt++)
    {
        int n;
        cin >> n;
        vector<int> s(n);
        for (int i = 0; i < n; i++)
            cin >> s[i];
        
    }
    
    return 0;
}