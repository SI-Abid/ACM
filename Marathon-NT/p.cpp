#include<bits/stdc++.h>
using namespace std;
const int SIZE = 20000000;
vector<bool> prime(SIZE+2,true);
vector<int> prime2;
void init(){
    // prime.assign(SIZE,true);
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
void solve(int n)
{
    int cnt=0;
    for(auto x:prime2)
    {
        if(x>n) break;
        if(prime[n-x])cnt++;
    }
    cout<<(cnt+1)/2<<endl;
}
int main()
{
    init();
    int t;
    cin>>t;
    for(int tc=1;tc<=t;tc++)
    {
        printf("Case %d: ",tc);
    
        int n;
        cin>>n;
        solve(n);
    }
    return 0;
}


void init(){
    // prime.assign(SIZE,true);
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