#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    vector<double> fact;
    fact.push_back(0);
    for(int i=1;i<1000002;i++)
    {
        fact.push_back(fact.back()+log10(i));
    }
    for(int tc=1;tc<=t;tc++)
    {
        printf("Case %d: ",tc);
    
        int n, base;
        cin>>n>>base;
        double ans=fact[n];
        cout<<setprecision(20)<<ceil((ans+1e-9)/log10(base))<<endl;
    }
    return 0;
}