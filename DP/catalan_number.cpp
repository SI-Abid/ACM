#include<bits/stdc++.h>
using namespace std;

unsigned long long catalan(int n)
{
    if(n<=1)
        return 1;
    unsigned long long catalan_n = 0;
    for(int i=0;i<n;i++)
        catalan_n += catalan(i)*catalan(n-i-1);
    return catalan_n;
}

int main()
{
    {  
        clock_t tStart = clock();
    
        for (int i = 0; i < 20; i++)
        {
            cout<<catalan(i)<<"  ";
        }
        cout<<"\n";
    
        clock_t tEnd = clock();
        double time = (tEnd - tStart) / (double)CLOCKS_PER_SEC;
        printf("Time taken: %.10lf seconds\n", time);
    }
    return 0;
}