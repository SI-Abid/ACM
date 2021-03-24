#include"iostream"
using namespace std;

int main()
{
    int t;
    cin>>t;
    for(int i=1; i<=t; i++)
    {
        int l, r, sum=0;
        cin>>l>>r;
        while(l<=r)
        {
            if(l&1)
                sum+=l;
            l++;
        }
        cout<<"Case "<<i<<": "<<sum<<endl;
    }
    return 0;
}