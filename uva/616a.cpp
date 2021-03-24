#include "bits/stdc++.h"
using namespace std;

int main()
{
    string a, b;
    cin>>a>>b;
    int n, m;
    n=a.size();
    m=b.size();
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    while (n < m) 
    {
        a += '0';
        n++;
    }
    while (m < n) 
    {
        b += '0';
        m++;
    }
    int p = n - 1;
    while (p >= 0 && a[p] == b[p]) 
        p--;
    if (p < 0) 
        puts("=");
    else if (a[p] < b[p]) 
        puts("<");
    else 
        puts(">");
    return 0;
}