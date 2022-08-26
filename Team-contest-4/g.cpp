#include <bits/stdc++.h>
using namespace std;

map<pair<string, string>, bool> m;
bool comp(string a, string b)
{
    if (m[{a, b}])
        if(a.size()==b.size())
            return a<b;
        else
            return a.size()<b.size();
    return false;
}

int main()
{
    int n, r, l;
    cin >> n >> r >> l;
    vector<string> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    for (size_t i = 0; i < r; i++)
    {
        string a, b;
        cin >> a >> b;
        m[{a, b}] = true;
        m[{b, a}] = true;
    }
    v.resize(l);
    for (size_t i = 0; i < l; i++)
    {
        cin >> v[i];
    }
    sort(v.begin(), v.end(), comp);
    for (size_t i = 0; i < v.size(); i++)
    {
        cout << v[i] << ' ';
    }
    cout << endl;
    // sort(v.begin(), v.end());
    // for (size_t i = 0; i < v.size(); i++)
    // {
    //     cout << v[i] << ' ';
    // }
    return 0;
}