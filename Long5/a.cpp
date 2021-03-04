#include <bits/stdc++.h>
using namespace std;

const int mx = 1e5;
bool status[mx];

void prime()
{
    memset(status, true, mx);
    status[1]=false;
    for(int i=2; i*i<=mx; i++)
    {
        if(status[i])
        {
            for(int j=i*i; j<=mx; j+=i)
            {
                status[j]=false;
            }
        }
    }

}


int main()
{
    prime();
    string s;
    //cin >> s;
    while(cin >> s)
    {
        int sum = 0;
        for(int i=0; i<s.size(); i++)
        {
            if(islower(s[i]))
            {
                sum += s[i]-'a' + 1;
            }
            else
            {
                sum += s[i]-'A' + 27;
            }
        }

        if(status[sum])
        {
            cout << "It is a prime word." << endl;
        }
        else
        {
            cout << "It is not a prime word." << endl;
        }
    }
    return 0;
}