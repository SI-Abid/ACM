#include<bits/stdc++.h>
using namespace std;

char caseSwap(char c)
{
    return c^1<<5;
}

int main()
{
    cout<<caseSwap('a')<<endl;
    // vector<int> v;
    // cout<<v.max_size()<<endl;
    // int n;
    // cin>>n;
    // vector<vector<int>> v;
    // int x;
    // cin>>x;
    // v.emplace_back();
    // v[0].push_back(x);
    // for(int i=1;i<n;i++)
    // {
    //     cin>>x;
    //     bool flag=true;
    //     for(auto &k:v)
    //     {
    //         if(x>k.back())
    //         {
    //             k.push_back(x);
    //             flag=false;
    //             break;
    //         }
    //     }
    //     if(flag)
    //     {
    //         v.emplace_back();
    //         v.back().push_back(x);
    //     }
    // }
    // for(auto &k:v)
    // {
    //     for(auto &j:k)
    //     {
    //         cout<<j<<" ";
    //     }
    //     cout<<endl;
    // }
    return 0;
}