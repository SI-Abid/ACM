#include"iostream"
using namespace std;

int main()
{
    // freopen("in.txt","r",stdin);
    long long a, b, d1, d2;
    while(true)
    {
        cin>>a>>b;
        if(a==0 && b==0)
            return 0;
        long long carry=0, cache=0;
        while(a>0 || b>0)
        {
            d1=a%10, d2=b%10;
            if((d1+d2+cache)>9)
            {
                carry++;
                cache=1;
            }
            else
            {
                cache=0;
            }
            // puts(".");
            a/=10;
            b/=10;
        }
        switch (carry)
        {
        case 0: puts("No carry operation.");
            break;
        case 1: puts("1 carry operation.");
            break;
        default:
                cout<<carry<<" carry operations."<<endl;
            break;
        }
    }
}