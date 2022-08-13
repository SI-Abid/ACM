// segment tree
#include<bits/stdc++.h>
using namespace std;

struct node{
    int val;
    node *left, *right;
    node(){
        val = INT_MAX;
        left = right = NULL;
    }
    ~node(){
        delete left;
        delete right;
    }  
};

void build(node *root, int l, int r, vector<int> &v){
    if(l == r){
        root->val = v[l-1];
        return;
    }
    int mid = (l + r) / 2;
    root->left = new node();
    root->right = new node();
    build(root->left, l, mid, v);
    build(root->right, mid + 1, r, v);
    root->val = min(root->left->val, root->right->val);
}

int query(node *root, int l, int r, int ql, int qr){
    if(ql > r or qr < l)
        return INT_MAX;
    if(ql <= l and qr >= r)
        return root->val;
    int mid = (l + r) / 2;
    return min(query(root->left, l, mid, ql, qr), query(root->right, mid + 1, r, ql, qr));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t, tc=1;
    cin>>t;
    while(t--)
    {
        cout<< "Case "<<tc++<<":\n";
        int n,q;
        cin>>n>>q;
        vector<int> v(n);
        for(int i = 0; i < n; i++)
            cin>>v[i];
        node *root = new node();
        build(root, 1, n, v);
        while(q--)
        {
            int ql,qr;
            cin>>ql>>qr;
            cout<<query(root, 1, n, ql, qr)<<endl;
        }
    }
    return 0;
}