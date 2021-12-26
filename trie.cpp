#include<bits/stdc++.h>
using namespace std;

class Node
{
public:
    bool end;
    Node *next[26];
    Node()
    {
        for(int i=0;i<26;i++)
        {
            next[i]=NULL;
        }
    }
    void insert(string s)
    {
        int len=s.size();
        Node *curr=this;
        for(int i=0;i<len;i++)
        {
            int index=s[i]-'a';
            if(curr->next[index]==NULL)
            {
                curr->next[index]=new Node();
            }
            curr=curr->next[index];
        }
        curr->end=true;
    }
    bool search(string s)
    {
        int len=s.size();
        Node *curr=this;
        for(int i=0;i<len;i++)
        {
            int index=s[i]-'a';
            if(curr->next[index]==NULL)
            {
                return false;
            }
            curr=curr->next[index];
        }
        return curr->end;
    }
    void del(Node *cur)
    {
        for(int i=0;i<26;i++)
        {
            if(cur->next[i]!=NULL)
            {
                del(cur->next[i]);
            }
        }
        delete cur;
    }
};


int main()
{
    puts("Enter number of words");
    Node *root=new Node();
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        string s;
        cin>>s;
        root->insert(s);
    }
    puts("Enter number of queries");
    int q;
    cin>>q;
    for(int i=0;i<q;i++)
    {
        string s;
        cin>>s;
        if(root->search(s))
        {
            puts("Found");
        }
        else
        {
            puts("Not Found");
        }
    }
    root->del(root);
    return 0;
}