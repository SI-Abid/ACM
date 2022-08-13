#include<bits/stdc++.h>
using namespace std;

template <typename T>
istream& operator>>(istream& in, vector<T>& v) {
    for (T& x : v) in >> x;
    return in;
}

template <typename T>
ostream& operator<<(ostream& out, const vector<T>& v) {
    for (const T& x : v) out << x << " ";
    return out;
}

int main()
{
    int t,tc=1;cin>>t;
    
    while(t--)
    {
        int n,k;cin>>n>>k;
        vector<int> a(n);
        cin>>a;
        vector<int> pre(n+1);
        pre[0]=0;
        for(int i=1;i<=n;i++)
        {
            pre[i]=pre[i-1]+a[i-1];
        }
        int ans=INT_MAX;
        for(int i=0;i<=n-k;i++)
        {
            ans=min(ans,pre[i+k]-pre[i]);
        }
        cout<< "Case " << tc++ << ": " << ans << '\n';
    }
    return 0;
}