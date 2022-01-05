#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t-->0)
    {
        long long n;
        cin>>n;
        double ans = n/2 + n/3 - 2*(n/6);
        printf("%.3lf\n",ans/n);
    }
    return 0;
}
