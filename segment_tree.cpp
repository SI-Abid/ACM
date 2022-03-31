#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int val;
    Node *left, *right;
    Node()
    {
        val = INT_MAX;
        left = right = NULL;
    }
};

void build(Node *root, int l, int r, vector<int> &v)
{
    if (l==r)
    {
        root->val = v[l];
        return;
    }
    int mid = (l+r)/2;
    root->left = new Node();
    root->right = new Node();
    build(root->left, l, mid, v);
    build(root->right, mid+1, r, v);
    root->val = min(root->left->val, root->right->val);
}

void update(Node *root, int l, int r, int pos, int val, vector<int> &v)
{
    if (l==r)
    {
        v[pos] = val;
        root->val = val;
        return;
    }
    int mid = (l+r)/2;
    if (pos<=mid)
        update(root->left, l, mid, pos, val, v);
    else
        update(root->right, mid+1, r, pos, val, v);
    root->val = min(root->left->val, root->right->val);
}

int query(Node *root, int l, int r, int ql, int qr)
{
    if (l>qr or r<ql)
        return INT_MAX;
    if (l>=ql and r<=qr)
        return root->val;
    int mid = (l+r)/2;
    return min(query(root->left, l, mid, ql, qr), query(root->right, mid+1, r, ql, qr));
}

int main()
{
    int n, q;
    cin>>n>>q;
    vector<int> v(n);
    for (int i=0; i<n; i++)
        cin>>v[i];
    Node *root = new Node();
    build(root, 0, n-1, v);
    while (q--)
    {
        char type;
        int l, r, val, pos;
        cin>>type;
        if (type=='u')
        {
            cin>>pos>>val;
            update(root, 0, n-1, pos-1, val, v);
        }
        else
        {
            cin>>l>>r;
            cout<<query(root, 0, n-1, l-1, r-1)<<endl;
        }
    }
    return 0;
}