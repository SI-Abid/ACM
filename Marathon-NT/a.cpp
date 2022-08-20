#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    for(int tc=1;tc<=t;tc++)
    {
        printf("Case %d: ",tc);
    
        long long n;
        cin>>n;
        if(n&1)
        {
            cout<<"Impossible\n";
        }
        else
        {
            for(long long i=2;i<n;i*=2)
            {
                if((n/i)%2==1)
                {
                    cout<<n/i<<' '<<i<<endl;
                    break;
                }
            }
        }
    }
    return 0;
}