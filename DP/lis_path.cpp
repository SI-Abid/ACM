#include <bits/stdc++.h>
using namespace std;

#define MAXN 100
#define EMPTY -1

int mem[MAXN];
int _next[MAXN];

int f(int i, vector<int> &A)
{
    if (mem[i] != EMPTY)
        return mem[i];

    int ans = 0;
    for (int j = i + 1; j < A.size(); j++)
    {
        if (A[j] > A[i])
        {
            int sub = f(j, A);
            if (sub > ans)
            {
                ans = sub;
                _next[i] = j;
            }
        }
    }
    return mem[i] = ans + 1;
}

vector<int> LIS(vector<int> A)
{
    int ans = 0;
    memset(mem, EMPTY, sizeof(mem));
    memset(_next, EMPTY, sizeof(_next));
    int start = -1;

    for (int i = 0; i < A.size(); i++)
    {
        int res = f(i, A);
        if (res > ans)
        {
            ans = res;
            start = i;
        }
    }
    vector<int> path;
    while (start != -1)
    {
        path.push_back(A[start]);
        start = _next[start];
    }
    return path;
}

int main()
{
    vector<int> a{2,0,2, 3, 2, 1, 3, 5};
    for (auto p : LIS(a))
    {
        cout << p << " -> ";
    }
    cout << "END\n";
    return 0;
}