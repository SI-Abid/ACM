#include<bits/stdc++.h>
using namespace std;

#define ll long long

struct Node
{
    int cnt;
    Node *next[52];
    Node()
    {
        cnt=0;
        for(int i=0;i<52;i++)
        {
            next[i]=NULL;
        }
    }
    char convert(const char &c)
    {
        return isupper(c) ? c-'A'+26 : c-'a';
    }
    void insert(string s)
    {
        int len=s.size();
        Node *curr=this;
        for(int i=0;i<len;i++)
        {
            int index=convert(s[i]);
            if(curr->next[index]==NULL)
            {
                curr->next[index]=new Node();
            }
            curr=curr->next[index];
        }
        curr->cnt++;
    }
    int search(string s)
    {
        int len=s.size();
        Node *curr=this;
        for(int i=0;i<len;i++)
        {
            int index=convert(s[i]);
            if(curr->next[index]==NULL)
            {
                return 0;
            }
            curr=curr->next[index];
        }
        // cout<<"cnt: "<<curr->cnt<<'\n';
        return curr->cnt;
    }
    void del(Node *cur)
    {
        for(int i=0;i<52;i++)
        {
            if(cur->next[i]!=NULL)
            {
                del(cur->next[i]);
            }
        }
        delete cur;
    }
};


int main(int argc, char const *argv[])
{
    #ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
    #endif
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);

    int t,tc=0;
    cin>>t;
    while(t--)
    {
        Node *root=new Node();
        // map<string,ll>mp;
        int n;
        cin>>n;
        while(n--)
        {
            string s;
            cin>>s;
            if(s.size()>2)
                sort(s.begin()+1,s.end()-1);
            root->insert(s);
            // mp[s]++;
        }
        int q;
        cin>>q;
        cout<< "Case "<<++tc<<":\n";
        getchar();
        while(q--)
        {
            string line;
            getline(cin,line);
            // cout<<line.size()<<'\n';
            string word;
            stringstream ss(line);
            ll ans=1;
            while(ss>>word)
            {
                if(word.size()>2)
                    sort(word.begin()+1,word.end()-1);
                ans*=root->search(word);
                // ans*=mp[word];
            }
            cout<<ans<<'\n';
        }
        root->del(root);
        // mp.clear();
    }
    return 0;
}