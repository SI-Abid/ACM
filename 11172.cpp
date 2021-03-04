#include "iostream"
using namespace std;

int main()
{
    int t;
    for(cin>>t;t;t--)
    {
        int a, b;
        cin>>a>>b;
        if(a>b)
            puts(">");
        else if(a<b)
            puts("<");
        else 
            puts("=");
    }
    return 0;
}