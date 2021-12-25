#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, q;
    cin>>n>>q;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin>>v[i];
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < q; i++)
    {
        int x;
        cin>>x;
        cout<<n-(lower_bound(v.begin(), v.end(), x) - v.begin())<<endl;
    }

    return 0;
}