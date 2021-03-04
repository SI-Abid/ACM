#include<bits/stdc++.h>
#define ll long long int
#define pb push_back
using namespace std;
int main()
{
    int k,n,w;
    cin>>k>>n>>w;
    int sum=(w*(w+1)/2)*k;
    
    if(sum-n<0)
        puts("0");

    else
    {
        cout<<sum-n<<endl;
    }
    
    return 0;
}