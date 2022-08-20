#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    for(int tc=1;tc<=t;tc++)
    {
        // printf("Case %d: ",tc);
    
        long double h,s;
        cin>>h>>s;
        long double base = h/sqrtl(2.0);
        long double maxArea = (base*base*0.5);
        if(base*base<2*s)
        {
            cout<<"-1"<<endl;
            continue;
        }
        long double low = 0;
        long double high = base;
        for(int i=0;i<100;i++)
        {
            long double mid = (low+high)/2;
            long double b = sqrtl(h*h-mid*mid);
            long double area = (mid*b);
            if(area<2*s)
            {
                low = mid;
            }
            else
            {
                high = mid;
            }
        }
        long double otherSide = sqrtl(h*h-low*low);
        vector<long double> ans = {h,low,otherSide};
        sort(ans.begin(),ans.end());
        for(auto x:ans)
        {
            cout<<fixed<<setprecision(6)<<x<<" ";
        }
        cout<<endl;
    }
    return 0;
}