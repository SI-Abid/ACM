#include<bits/stdc++.h>
using namespace std;

#define PI acos(-1)
#define R 6371009
#define Rad(x) ((x)*PI/180)

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        double lat1,lon1,lat2,lon2;
        cin>>lat1>>lon1>>lat2>>lon2;
        double phi1 = Rad(lat1);
        double phi2 = Rad(lat2);
        double delta_phi = Rad(lat2-lat1);
        double delta_lambda = Rad(lon2-lon1);

        double a = sin(delta_phi/2)*sin(delta_phi/2) + cos(phi1)*cos(phi2)*sin(delta_lambda/2)*sin(delta_lambda/2);
        double c = 2*atan2(sqrt(a),sqrt(1-a));
        double s = R*c;
        double d = R*sin(c)/sin((PI-c)/2);
        // cout<<setprecision(10)<<s<<"\n";
        // cout<<setprecision(10)<<d<<"\n";
        cout<<round(s-d)<<"\n";
        // cout << len2 - len1<< '\n';
    }
    return 0;
}