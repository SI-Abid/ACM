#include<bits/stdc++.h>
using namespace std;

vector<int> v;
string arr = "+-*";

void solve(vector<int> x)
{
    // cout<<x.size()<<endl;
    if(x.size()==1)
    {
        // puts("---");
        v.push_back(x[0]);
        // cout<<x[0]<<" ";
        return;
    }

    // puts("---");
    int p = x[x.size()-1];
    // int q = x[x.size()-1];
    x.pop_back();
    // x.pop_back();

    for(int i=0;i<3;i++)
    {
        if(arr[i]=='+')
        {
            // puts("+");
            x[x.size()-1] += p;
            // cout<<x.back()<<" back, ";
            solve(x);
        }
        else if(arr[i]=='-')
        {
            // puts("-");
            x[x.size()-1] -= p;
            // cout<<x.back()<<" back, ";
            solve(x);
        }
        else
        {
            // puts("*");
            x[x.size()-1] *= p;
            // cout<<x.back()<<" back, ";
            solve(x);
        }
    }
}

int main()
{
    // arr = "+-*";
    int a,b,c,d,e;
    while (cin>>a>>b>>c>>d>>e)
    {
        if(a+b+c+d+e==0)
        {
            break;
        }
        vector<int> x = {a,b,c,d,e};
        // cout<<x.size()<<endl;
        do
        {
            solve(x);
        }while(next_permutation(x.begin(),x.end()));

        // cout<< v.size()<<endl;
        sort(v.begin(),v.end());
        // for(int i=0;i<v.size();i++)
        // {
        //     cout<<v[i]<<" ";
        // }
        // cout<<endl;
        if(binary_search(v.begin(),v.end(),23))
        {
            cout<<"Possible\n";
        }
        else
        {
            cout<<"Impossible\n";
        }
        
        v.clear();
    }
    return 0;
}