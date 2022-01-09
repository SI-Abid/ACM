#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    int even=0,odd=0, odd_pos, even_pos;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        if(x%2==0)
        {
            even++;
            even_pos=i+1;
        }
        else
        {
            odd++;
            odd_pos=i+1;
        }
    }
    cout<< (even==1? even_pos : odd_pos) << endl;
    return 0;
}