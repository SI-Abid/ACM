#include<bits/stdc++.h>
using namespace std;

struct node
{
    int cnt[3];
    node *left,*right;
    node()
    {
        cnt[0]=cnt[1]=cnt[2]=0;
        left=right=NULL;
    }
};

void build(node *root, int l, int r)
{
    if(l==r)
    {
        root->cnt[0]=1;
        root->cnt[1]=root->cnt[2]=0;
        return;
    }
    int mid=(l+r)/2;
    root->left=new node();
    root->right=new node();
    build(root->left,l,mid);
    build(root->right,mid+1,r);
    root->cnt[0]=root->left->cnt[0]+root->right->cnt[0];
    root->cnt[1]=root->left->cnt[1]+root->right->cnt[1];
    root->cnt[2]=root->left->cnt[2]+root->right->cnt[2];
}

void increase(node *root, int l, int r, int i, int j)
{
    if(l>j || r<i)
        return;
    if(l>=i && j>=r)
    {
        // cyclic shift
        root->cnt[0]=(root->cnt[0]+1)%3;
        root->cnt[1]=(root->cnt[1]+1)%3;
        root->cnt[2]=(root->cnt[2]+1)%3;
        return;
    }
    int mid=(l+r)/2;
    increase(root->left,l,mid,i,j);
    increase(root->right,mid+1,r,i,j);
    root->cnt[0]=root->left->cnt[0]+root->right->cnt[0];
    root->cnt[1]=root->left->cnt[1]+root->right->cnt[1];
    root->cnt[2]=root->left->cnt[2]+root->right->cnt[2];
}

int query(node *root, int l, int r, int i, int j)
{
    if(l>j || r<i)
        return 0;
    if(l>=i && j>=r)
        return root->cnt[0];
    int mid=(l+r)/2;
    return query(root->left,l,mid,i,j)+query(root->right,mid+1,r,i,j);
}

void del(node *root)
{
    if(root==NULL)
        return;
    del(root->left);
    del(root->right);
    delete root;
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("in","r",stdin);
    #endif
    ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    
    int t;
    cin>>t;
    int tc=0;
    while(t--)
    {
        int n,q;
        cin>>n>>q;
        node *root = new node();
        build(root,0,n-1);
        cout<<"Case "<<++tc<<":\n";
        while(q--)
        {
            int c,i,j;
            cin>>c>>i>>j;
            if(c)
            {
                cout<<query(root,0,n-1,i,j)<<"\n";
            }
            else
            {
                increase(root,0,n-1,i,j);
                for (int i = 0; i < n; i++)
                {
                    cout<<query(root,0,n-1,i,i)<<" ";
                }
                cout<< "\n";
            }
        }
        del(root);
    }
    return 0;
}