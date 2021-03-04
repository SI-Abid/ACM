#include <bits/stdc++.h>
#define F first
#define S second

using namespace std;


int main()
{
    // freopen("in.txt", "r", stdin);
    int n;
    string s;
    cin>>n>>s;
    set<pair<int, string>> spis;
    for(int i=0; i<n-1; i++)
    {
        string str=s.substr(i, 2);
        int counter=0;
        for(int i=0; i<n-1; i++)
        {
            string sub=s.substr(i, 2);
            if(sub==str)
            {
                counter++;
            }
        }
        spis.insert(make_pair(counter, str));
    }
    // cout<<spis.size()<<endl;
    // for(auto q=spis.begin(); q!=spis.end(); q++)
    // {
    //     // int counter=0;
    //     // string sample = q->F;
    //     // int cnt = q->S;
    //     // for(int i=0; i<n-1; i++)
    //     // {
    //     //     string sub=s.substr(i, 2);
    //     //     if(sub==sample)
    //     //     {
    //     //         counter++;
    //     //     }
    //     // }
    //     // spis.erase(spis.find(make_pair(sample, cnt)));
    //     // spis.insert(make_pair(sample, counter));
    //     cout<<q->F<<" "<<q->S<<endl;
    // }
    auto it = spis.rbegin();
    cout<<it->S<<endl;
    return 0;
}