#include <bits/stdc++.h>
using namespace std;
int main()
{
    int i;
    bool down = true;
    double r, d;
    vector<double> v(5);
    for (i = 0; i < 5; i++)
    {
        cin >> v[i];
    }
    for (i = 1; i < 5; i++)
    {
        // or if(abs(v[i]/v[i-1])>=1)
        if (v[i] / v[i - 1] >= 1 || v[i] / v[i - 1] <= -1) // ratio need to be between 1 to -1, exclusively
        {
            down = false;
            break;
        }
    }
    puts(down ? "YES" : "NO");
    return 0;
}
