#include<bits/stdc++.h>
using namespace std;

struct trie
{
    int val;
    trie *child[26];
    trie()
    {
        val=0;
        for(int i=0;i<26;i++)
            child[i]=NULL;
    }
    ~trie()
    {
        for(int i=0;i<26;i++)
            if(child[i])
                delete child[i];
    }
    void insert(string s)
    {
        trie *cur=this;
        for(int i=0;i<s.size();i++)
        {
            if(cur->child[s[i]-'A']==NULL)
                cur->child[s[i]-'A']=new trie();
            cur=cur->child[s[i]-'A'];
        }
        cur->val++;
    }
    int query(string s)
    {
        trie *cur=this;
        for(int i=0;i<s.size();i++)
        {
            if(cur->child[s[i]-'A']==NULL)
                return 0;
            cur=cur->child[s[i]-'A'];
        }
        return cur->val;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        trie *root=new trie();
        string tmp="";
        for(int i=0;i<s.size();i++)
        {
            tmp+=s[i];
            root->insert(tmp);
        }
    }
    return 0;
}