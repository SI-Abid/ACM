#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int> v(n);
    bool flag = false;
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
        if(v[i] > i+1)
            flag = true;
    }
    if(flag)
    {
        cout<<"-1\n";
        return 0;
    }
    int ans = 0;
    for (int i = n - 1; i >= 0;)
    {
        if(v[i]<=ans)
        {
            cout<<v[i]<<"\n";
            i--;
        }
        else
        {
            int target = v[i]-1;
            queue<int> q;
            while(v[i] != target)
            {
                q.push(v[i]);
                i--;
            }
        }
    }
    
    return 0;
}