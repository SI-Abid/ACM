#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int> v(n), w(n);
    for(int i=0;i<n;i++)   cin>>v[i], w[i]=v[i];
    
    sort(v.begin(), v.end());
    int s=0;
    for(int i=0;i<n;i++)
        if(v[i]!=w[i])
            s++;

    if(s>2)
        cout<<"NO"<<endl;
    else
        cout<<"YES"<<endl;
    return 0;
}