#include<bits/stdc++.h>
using namespace std;


int main()
{
    int n;
    cin>>n;
    vector<string> v;
    set<string> s;
    for (int i = 0; i < n; i++)
    {
        string x;
        cin>>x;
        v.push_back(x);
        s.insert(x);
    }
    pair<string, int> mx = {"", 0};
    for(auto y:s)
    {
        int cnt=0;
        for(auto x:v)
        {
            if(x==y)
                cnt++;
        }
        if(cnt>mx.second)
        {
            mx.first=y;
            mx.second=cnt;
        }
    }
    cout<<mx.first<<endl;
}