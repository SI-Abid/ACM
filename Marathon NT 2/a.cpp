// (2n)!/2 (mod 1e9+7)
#include<bits/stdc++.h>
using namespace std;

long long binPow(long long a, long long b, long long m) {
    long long res = 1;
    while (b > 0) {
        if (b & 1) {
            res = res * a % m;
        }
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

// n*(n-1)*(n-2)*...*3
void build(vector<long long>& f) {
    long long ans = 1;
    for (int i = 2; i < f.size(); i++) {
        ans = (ans * i) % 1000000007;
        f[i] = ans;
    }
}

signed main()
{
    int _;
    cin>>_;
    vector<long long> f(3000001);
    build(f);
    for(int tc=1;tc<=_;tc++)
    {
        // printf("Case %d: ",tc);
    
        int n;
        cin>>n;
        cout<< (f[2*n] * binPow(2, 1000000005, 1000000007)) % 1000000007 <<endl;
    
    }
    return 0;
}