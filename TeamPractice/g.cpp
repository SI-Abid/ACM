#include<iostream>
#include<map>
using namespace std;

int main()
{
    string s="Programming Club, CSE CoU.";
    map<char,int>m;
    for(char c:s)
    {
        m[c]++;
    }
    for(auto x:m)
        cout<<x.first<<" "<<x.second<<endl;
    return 0;
}