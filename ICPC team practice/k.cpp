#include<bits/stdc++.h>
using namespace std;

string str(int x)
{
    string s;
    if(x==0)
        return "0";
    while(x)
    {
        s.push_back(x%2+'0');
        x/=2;
    }
    reverse(s.begin(),s.end());
    return s;
}

template<typename T>
ostream &operator<<(ostream &os, const vector<T> &v)
{
    os << "[";
    for (int i = 0; i < v.size(); i++)
    {
        os << v[i];
        if (i != v.size() - 1)
            os << ", ";
    }
    os << "]";
    return os;
}

int main()
{
    int t=1;
    cin>>t;
    for(int tc=1;tc<=t;tc++)
    {
        // printf("Case %d: ",tc);
    
        // string s="0110";
        // int c=2;
        // for(int i=3;i<100;i++)
        // {
        //     s+=str(i);
        // }
        // vector<int>v(1,0);
        // for (size_t i = 0; i < s.size();)
        // {
        //     if(s[i]=='1')
        //     while(i<s.size() and s[i]=='1')
        //     {
        //         v[v.size()-1]++;
        //         i++;
        //     }
        //     else
        //         i++;
        //     v.push_back(0);
        // }
        // FILE *f=fopen("k.out","w");
        // fprintf(f,"%s\n",s.c_str());
        // fclose(f);
        // int mx=0;
        // c=1;
        // for (size_t i = 0; i < v.size(); i++)
        // {
        //     if(v[i]>mx)
        //     {
        //         mx=v[i];
        //         cout<<c<<' ';
        //     }
        //     v[i]=mx;
        //     c+=v[i];
        // }
        
        // cout<<v<<endl;
        vector<long long>series;
        long long n = 0;
        long long x;
        do
        {
            x = (n-1)*(1<<n)+2;
            series.push_back(x);
            n++;
        } while (x<=1e9);
        // cout<<series<<endl;
        int k;
        cin>>k;
        cout<<lower_bound(series.begin(),series.end(),k)-series.begin()<<'\n';
    }
    return 0;
}