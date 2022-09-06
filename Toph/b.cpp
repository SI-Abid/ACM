#include<bits/stdc++.h>
using namespace std;

vector<int> prime2;

void init(int SIZE=1000000){
    // prime.assign(SIZE,true);
    vector<bool> prime(SIZE,true);
    prime[0]=prime[1]=false;
    for(int i=4;i<=SIZE;i+=2){
        prime[i]=false;
    }
    for(int i=3;i*i<=SIZE;i+=2){
        if(prime[i]){
            for(int j=i*i;j<=SIZE;j+=i){
                prime[j]=false;
            }
        }
    }
    for(int i=2;i<=SIZE;i++)
    {
        if(prime[i])prime2.push_back(i);
    }
}

int main()
{
    init();
    int n;
    cin>>n;
    vector<int> v(n);
    vector<int> ps(1000005,0);
    // cout<<prime2.size()<<endl;
    for (int i = 0; i < n; i++)
    {
        cin>>v[i];
        int tmp=v[i];
        for (int j = 0; j < prime2.size(); j++)
        {
            if(tmp%prime2[j]==0){
                ps[prime2[j]]++;
                while(tmp%prime2[j]==0)tmp/=prime2[j];
            }
        }
        if(tmp>1)
            ps[tmp]++;
    }
    // print map
    // for(auto it=ps.begin();it!=ps.end();it++)
    // {
    //     cout<<it->first<<" "<<it->second<<endl;
    // }
    // get the key with max value
    int mx1=0,mx2=0,mx1k=1605113,mx2k=1605113;
    for(int i=2;i<=1000000;i++)
    {
        if(ps[i]>mx1)
        {
            mx1=ps[i];
            mx1k=i;
        }
    }
    for(int i=2;i<=1000000;i++)
    {
        if(ps[i]>mx2 && i!=mx1k)
        {
            mx2=ps[i];
            mx2k=i;
        }
    }
    int ans=n;
    for(int i=0;i<n;i++)
    {
        if(v[i]%mx1k==0 or v[i]%mx2k==0)
            ans--;
    }
    cout<<ans<<'\n';
    cout<<mx1k<<" "<<mx2k<<'\n';
    return 0;
}