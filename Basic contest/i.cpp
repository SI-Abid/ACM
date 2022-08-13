#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    if(n<4)
    {
        cout<<"NO\n";
        return 0;
    }
    cout<<"YES\n";
    vector<int> a;
    for(int i=0;i<n-4;i++)
    {
        a.push_back(i+5);
    }
    if(a.size()%2==0)
    {
        for(int i=0;i<a.size();i+=2)
        {
            cout<<a[i+1]<<" - "<<a[i]<<" = 1\n";
            cout<<"1 * 1 = 1\n";
        }
        cout<<"1 * 2 = 2\n2 * 3 = 6\n6 * 4 = 24\n";
    }
    else
    {
        for (int i = 1; i < a.size(); i+=2)
        {
            cout<<a[i+1]<<" - "<<a[i]<<" = 1\n";
            cout<<"1 * 1 = 1\n";
        }
        cout<<"5 - 1 = 4\n4 - 2 = 2\n2 * 3 = 6\n6 * 4 = 24\n";
    }
    return 0;
}