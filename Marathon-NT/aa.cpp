#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

template <typename T>
T gcd(T a, T b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

template <typename T>
T lcm(T a, T b)
{
    return a * b / gcd(a, b);
}

int main()
{
    int t;
    cin >> t;
    for (int tc = 1; tc <= t; tc++)
    {
        printf("Case %d: ", tc);

        long long a, b;
        long long l;
        cin >> a >> b >> l;
        long long l1 = lcm(a, b);
        if (l % l1 == 0)
        {
            long long c = l / l1;
            long long g = gcd(l1, c);
            while (g != 1)
            {
                l1 /= g;
                c *= g;
                g = gcd(l1, c);
            }
            cout<<c<<endl;
        }
        else
        {
            cout<<"impossible\n";
        }
    }
    return 0;
}