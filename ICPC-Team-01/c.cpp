#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    for(int tc=1;tc<=t;tc++)
    {
        // printf("Case %d: ",tc);
    
        int n;
        cin>>n;
        vector<int> a(n);
        map<int,int> m;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            m[a[i]]++;
        }
        vector<int> tmp;
        while(!m.empty())
        {
            for(auto it=m.begin(); it!=m.end(); it++)
            {
                tmp.push_back(it->first);
                it->second--;
                if(it->second==0)
                {
                    m.erase(it);
                }
            }
        }
        for(auto x:tmp)
        {
            cout<<x<<" ";
        }
        cout<<endl;
    }
    return 0;
}
// 1 2
// 2 1
// 3 1
// 4 2
