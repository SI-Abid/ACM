#include "bits/stdc++.h"
using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    int t, i=1;
    while(cin>>t)
    {
        if(t)
        {
            int tot=0, arr[t];
            for(int i=0; i<t; i++)
            {
                cin>>arr[i];
                tot+=arr[i];
            }
            int avg=tot/t, cnt=0;
            for(int i=0; i<t; i++)
            {
                if(arr[i]>avg)
                    cnt+=(arr[i]-avg);
            }
            cout<<"Set #"<<i++<<endl<<"The minimum number of moves is "<<cnt<<".\n\n";
        }   
        else
            return 0;
        
    }
}