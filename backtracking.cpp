#include<bits/stdc++.h>
using namespace std;

int taken[10001];

void generate(int idx, int &n, vector<int> &position)
{
    if(idx==n)
    {
        for(auto i:position)
        {
            cout<<i<<" ";
        }
        cout<<endl;
        return;
    }
    for (int i = 1; i <= n; i++)
    {
        if(taken[i]==0)
        {
            taken[i]=1;
            position[idx]=i;
            generate(idx+1,n,position);
            taken[i]=0;
        }
    }   
}

int main()
{
    vector<int> a = {1,2,3};
    int n=a.size();
    generate(0,n,a);
    return 0;
}