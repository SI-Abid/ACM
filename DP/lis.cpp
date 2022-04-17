#include<bits/stdc++.h>
using namespace std;

#define MAXN 100
#define EMPTY -1

int mem[MAXN];

int f(int i, vector<int> &a)
{
    if(mem[i]!=EMPTY)
        return mem[i];

    int ans=0;
    for (int j = i+1; j < a.size(); j++)
    {
        if(a[j]>a[i])
            ans=max(ans,f(j,a));
    }
    return mem[i]=ans+1;
}

int findLIS(vector<int> a)
{
    int ans=0;
    for (size_t i = 0; i < a.size(); i++)
    {
        mem[i]=EMPTY;
    }
    for (int i = 0; i < a.size(); i++)
    {
        ans=max(ans,f(i,a));
    }
    return ans;
}
int main()
{
    vector<int> a={5,0,9,2,7,3,4};
    cout<<findLIS(a)<<"\n";
    return 0;
}