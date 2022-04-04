#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    for(int tc=1;tc<=t;tc++)
    {
        vector<vector<int>> v(3,vector<int>(4));
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<4;j++)
            {
                cin>>v[i][j];
            }
        }
        vector<int> ans;
        int sum2=0;
        for(int i=0;i<4;i++)
        {
            int sum=v[0][i];
            for(int j=1;j<3;j++)
            {
                sum=min(sum,v[j][i]);
            }
            // sum=(sum/100000)*100000;
            ans.push_back(sum2>=1000000?0:min(sum,1000000-sum2));
            sum2+=sum;
            // cout<<ans.back()<<" <> ";
        }

        cout<<"Case #"<<tc<<": ";
        // int sum=ans[0]+ans[1]+ans[2]+ans[3];
        if(sum2<1000000)
        {
            cout<<"Impossible\n";
        }
        else
        {
            for(int j=0;j<4;j++)
            {
                cout<<ans[j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}