#include<bits/stdc++.h>
using namespace std;

int ways(int n, vector<int>& coins)
{
    if(n==0)
        return 1;
    if(n<0)
        return 0;
    int ans=0;
    for(int i=0;i<coins.size();i++)
    {
        ans+=ways(n-coins[i],coins);
    }
    return ans;
}

int main()
{
    // clock_t tStart = clock();
    int n=35;
    vector<int> coins={1,2,5};
    cout<<ways(n,coins)<<"\n";
    // clock_t tEnd = clock();
    // double time = (tEnd - tStart) / (double)CLOCKS_PER_SEC;
    // cout<<"Time taken: "<<time<<" seconds\n";
    return 0;
}