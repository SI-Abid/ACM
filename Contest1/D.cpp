#include "bits/stdc++.h"
#define ll long long
using namespace std;

int main()
{
    int t;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        vector<int> v(3);
        for(auto &x:v)
        {
            cin>>x;
        }
        sort(v.begin(), v.end());
        cout<<"Case "<<i<<": "<<v[1]<<endl;
    }
    return 0;
}