#include <bits/stdc++.h>
using namespace std;

int main()
{

    int n;
    cin>>n;
    set<int> s;
    while(n--)
    {
        int q, x;
        cin>>q>>x;
        switch (q)
        {
        case 1:
            s.insert(x);
            break;
        case 2:
            s.erase(x);
            break;
        case 3:
            puts(s.find(x)==s.end()?"No":"Yes");
            break;
        default:
            break;
        }

    }
    return 0;
}