#include<bits/stdc++.h>
using namespace std;

long double getArea(vector<long long> &pointX, vector<long long> &pointY)
{
    long double area = 0;
    for (int i = 0; i < pointX.size(); i++)
    {
        int j = (i + 1) % pointX.size();
        area += (pointX[i] * pointY[j] - pointX[j] * pointY[i]);
    }
    return abs(area / 2.0);
}

int main()
{
    long double ans = 0;
    int t;
    cin>>t;
    for(int tc=1;tc<=t;tc++)
    {
        int n;
        cin>>n;
        vector<long long> x(n),y(n);
        for (size_t i = 0; i < n; i++)
        {
            cin>>x[i]>>y[i];
        }
        ans+=getArea(x,y);
    }
    cout<<(long long)ans<<'\n';
    return 0;
}