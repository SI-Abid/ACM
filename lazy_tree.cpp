#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int val, lazy;
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

void build(Node *root, int l, int r, vector<int> &v)
{
    if (l == r)
    {
        root->val = v[l];
        return;
    }
    int mid = (l + r) / 2;
    root->left = new Node();
    root->right = new Node();
    build(root->left, l, mid, v);
    build(root->right, mid + 1, r, v);
    root->val = root->left->val + root->right->val;
}

void update(Node *root, int l, int r, int pos_i, int pos_j, int val)
{
    // outside the range
    if (pos_i > r or pos_j < l)
        return;
    // inside the range
    if (pos_i <= l and pos_j >= r)
    {
        root->lazy += val;
        root->val += (r - l + 1) * val;
        return;
    }
    int mid = (l + r) / 2;
    update(root->left, l, mid, pos_i, pos_j, val);
    update(root->right, mid + 1, r, pos_i, pos_j, val);
    root->val = root->left->val + root->right->val + root->lazy * (r - l + 1);
}

ll query(Node *root, int l, int r, int ql, int qr)
{
    // outside the range
    if (ql > r or qr < l)
        return 0;
    // inside the range
    if (ql <= l and qr >= r)
        return root->val + root->lazy * (r - l + 1);
    int mid = (l + r) / 2;
    
    return query(root->left, l, mid, ql, qr) + query(root->right, mid + 1, r, ql, qr);
}

int main()
{

    return 0;
}