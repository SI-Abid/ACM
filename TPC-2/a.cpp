#include<bits/stdc++.h>
using namespace std;

#define PI acos(-1)

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    double a,b;
    string c;
    while(cin>>a>>c>>b)
    {
        double rat = a/b;
        double w = 400/((PI*0.685)+2*rat);
        double l = w*rat;
        cout << "Case " << c << ": ";
        cout<< fixed << setprecision(7) << l << " " << fixed << setprecision(7) << w << '\n';

    }
    return 0;
}