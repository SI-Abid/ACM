#include<bits/stdc++.h>
using namespace std;

int maxDivide(int a,int b)
{
    while(a%b==0)
        a/=b;
    return a;
}

bool isUgly(int n)
{
    n=maxDivide(n,2);
    n=maxDivide(n,3);
    n=maxDivide(n,5);
    return n==1;
}

int getUgly(int n)
{
    int count=1;
    int i=1;
    while(count<n)
    {
        i++;
        if(isUgly(i))
            count++;
    }
    return i;
}

int main()
{
    clock_t tStart = clock();
    cout<<getUgly(1000)<<"\n";
    clock_t tEnd = clock();
    double time = (tEnd - tStart) / (double)CLOCKS_PER_SEC;
    printf("Time taken: %.10lf seconds\n", time);
    return 0;
}