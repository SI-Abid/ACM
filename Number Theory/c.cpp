#include<bits/stdc++.h>
using namespace std;

int main()
{
    // set<int> st;
    // st.insert(1);
    // for (int i = 1; i < 100000; i++)
    // {
    //     st.insert(i*2);
    // }
    // for (int i = 1; i < 100000; i++)
    // {
    //     st.insert(i*3);
    // }
    // for (int i = 1; i < 100000; i++)
    // {
    //     st.insert(i*5);
    // }
    // set<int>::iterator it=st.begin();
    // for (size_t i = 1; i < 1500; i++)
    // {
    //     it++;
    // }
    // cout<<i<<" "<<*it<<endl;
    vector<int> v = {2,3,5};
    // list all the numbers that are only divisible by 2,3,5
    set<int> st;
    for (int i = 1; i < 100; i++)
    {
        for (int j = 0; j < v.size(); j++)
        {
            while(i%v[j]==0)
            {
                i/=v[j];
            }
        }
        if(i==1)
        {
            st.insert(i);
        }
    }
    set<int>::iterator it=st.begin();
    for (size_t i = 1; i < 1500 and it!=st.end(); i++)
    {
        it++;
    }
    cout<<"The 1500'th ugly number is "<<*it <<".\n";
    return 0;
}