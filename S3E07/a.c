#include<stdio.h>
int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    int k=1;
    int p=n-m;
    while(p-->0)
        k*=32;

    printf("%d\n", k);
    return 0;
}
