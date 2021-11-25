#include<stdio.h>
int main()
{
    int k,n,m;
    scanf("%d%d%d",&k,&n,&m);
    if(k==10)
    {
        printf("%d",n+m);
        return 0;
    }
    int sum=0;
    while(n)
    {
        sum+=(n%10)*k;
    }
    return 0;
}