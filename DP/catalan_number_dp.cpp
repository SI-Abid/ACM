#include <bits/stdc++.h>
using namespace std;

unsigned long long catalan(int n)
{
    unsigned long long catalan_n[n + 1];

    catalan_n[0] = catalan_n[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        catalan_n[i] = 0;
        for (int j = 0; j < i; j++)
            catalan_n[i] += catalan_n[j] * catalan_n[i - j - 1];
    }
    return catalan_n[n];
}

int main()
{
    {
        clock_t tStart = clock();

        for (int i = 0; i < 10; i++)
        {
            cout << catalan(i) << " ";
        }
        cout << "\n";

        clock_t tEnd = clock();
        double time = (tEnd - tStart) / (double)CLOCKS_PER_SEC;
        printf("Time taken: %.10lf seconds\n", time);
    }
    return 0;
}