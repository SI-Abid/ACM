#include<bits/stdc++.h>
using namespace std;

int getUgly(int n)
{
    if(n>=1 and n<=5)
        return n;

    set<int> ugly;
    ugly.insert(1);
    n--;
    while(n--)
    {
        auto it = ugly.begin();
        int a = *it;
        ugly.erase(it);
        ugly.insert(a*2);
        ugly.insert(a*3);
        ugly.insert(a*5);
    }
    return *ugly.begin();
}

int main()
{
    {
        clock_t tStart = clock();
        cout<<getUgly(1000)<<"\n";
        clock_t tEnd = clock();
        double time = (tEnd - tStart) / (double)CLOCKS_PER_SEC;
        printf("Time taken: %.10lf seconds\n", time);
    }
    return 0;
}