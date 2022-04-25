#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;cin>>n;
        vector<int> a(n);
        for (size_t i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        sort(a.begin(),a.end());
        int cnt=0;
        for (size_t i = 0; i < n-1; i++)
        {
            if(a[i]==a[i+1])
            {
                cnt++;
            }
        }
        cout<<cnt<<endl;
    }
    return 0;
}
// 1 2 2 2 3 3 -> 1 2 4 6 3 5