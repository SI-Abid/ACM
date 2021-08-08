#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;

    if(stoi(s.substr(0,2))>12 and stoi(s.substr(2,2))<=12)
    {
        cout<<"YYMM"<<endl;
    }
    else if(stoi(s.substr(0,2))<=12 and stoi(s.substr(2,2))>12)
    {
        cout<<"MMYY"<<endl;
    }
    else if(stoi(s.substr(0,2))>12 and stoi(s.substr(2,2))>12)
    {
        cout<<"NA"<<endl;
    }
    else
    {
        cout<<"AMBIGUOUS"<<endl;
    }
    return 0;
}