#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    // find the index of 2nd max
    int m1, m2;
    int max1 = 0;
    int max2 = 0;
    for (int i = 0; i < n; i++) {
        if (v[i] > max1) {
            max2 = max1;
            max1 = v[i];
        } else if (v[i] > max2) {
            max2 = v[i];
            ans = i;
        }
    }
    cout << ans + 1 << endl;
    return 0;
}