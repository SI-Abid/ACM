#include<bits/stdc++.h>
using namespace std;

struct node
{
    int endp;
    node *next[26];
    node()
    {
        endp=0;
        for(int i=0;i<26;i++)
            next[i]=NULL;
    }
    void insert(string s)
    {
        int len = s.size();
        node *cur = this;
        for(int i=0;i<len; i++)
        {
            int id = s[i]-'a';
            if(!cur->next[id])
                cur->next[id]=new node();
            cur=cur->next[id];
        }
        cur->endp++;
    }
    long long search(string s)
    {
        int len=s.size();
        node *cur = this;
        long long ans = 0;
        int i=0;
        while(true)
        {
            int j=s[i%len]-'a';
            if(!cur->next[j])
                break;
            cur=cur->next[j];
            if(i>(len-1))
                ans+=cur->endp;
            i++;
        }
        return ans;
    }
    void del()
    {
        for(int i=0;i<26;i++)
        {
            if(!this->next[i])
                this->next[i]->del();
        }
        delete this;
    }
};


int main()
{
    node *root = new node();
    int t;
    cin>>t;
    vector<string> s(t);
    vector<int> n(t);
    for(int i=0;i<t;i++)
    {
        cin>>n[i]>>s[i];
        root->insert(s[i]);
    }
    long long ans =0 ;
    for (int i = 0; i < t; i++)
    {
        long long st=root->search(s[i]);
        ans+=(st*2+1);
    }
    cout<<ans<<endl;
    
    return 0;
}