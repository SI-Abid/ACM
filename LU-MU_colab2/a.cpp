#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<string> a(3);
    for (size_t i = 0; i < 3; i++)
    {
        cin >> a[i];
    }
    for (size_t i = 0; i < 3; i++)
    {
        cout<<(char)toupper(a[i][0]);
    }
    cout<<endl;
    return 0;
}