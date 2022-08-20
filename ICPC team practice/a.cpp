#include<iostream>
#include<vector>
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
        vector<string> a(n),b(n);
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        for(int i=0;i<n;i++)
        {
            cin>>b[i];
        }
        bool flag=true;
        for (int i = 0; i < n-1; i++)
        {
            int c=a[i].back()-'0';
            int d=b[i].back()-'0';
            if(c==1 or c==2)
            {
                if(d==3 or d==4)
                {
                    continue;
                }
                flag=false;
            }
            else
            {
                if(d==1 or d==2)
                {
                    continue;
                }
                flag=false;
            }
        }
        char c=a.back().back();
        char d=b.back().back();
        if(c=='1' or c=='2' or d=='3' or d=='4')
            flag=false;
        flag?cout<<"YES\n":cout<<"NO\n";
    }
    return 0;
}