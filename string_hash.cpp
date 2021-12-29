#include<bits/stdc++.h>
using namespace std;

#define mod 3803
#define d 26
 
int hash_b;
int* hash_a;
int* mul;
 
// Function to return the modular inverse
// using Fermat's little theorem
int mi(int x)
{
    int p = mod - 2;
    int s = 1;
    while (p != 1) {
        if (p % 2 == 1)
            s = (s * x) % mod;
        x = (x * x) % mod;
        p /= 2;
    }
 
    return (s * x) % mod;
}
 
// Function to generate hash
void genHash(string& a, string& b)
{
    // To store prefix-sum
    // of rolling hash
    hash_a = new int[a.size()];
 
    // Multiplier for different values of i
    mul = new int[a.size()];
 
    // Generating hash value for string b
    for (int i = b.size() - 1; i >= 0; i--)
        hash_b = (hash_b * d + (b[i] - 97)) % mod;
 
    // Generating prefix-sum of hash of a
    mul[0] = 1;
    hash_a[0] = (a[0] - 97) % mod;
    for (int i = 1; i < a.size(); i++) {
        mul[i] = (mul[i - 1] * d) % mod;
        hash_a[i]
            = (hash_a[i - 1] + mul[i] * (a[i] - 97)) % mod;
    }
}
 
// Function that returns true if the
// required sub-string in a is equal to b
bool checkEqual(int i, int len_a, int len_b)
{
    // To store hash of required
    // sub-string of A
    int x;
 
    // If i = 0 then
    // requires hash value
    if (i == 0)
        x = hash_a[len_b - 1];
 
    // Required hash if i != 0
    else {
        x = (hash_a[i + len_b - 1] - hash_a[i - 1]
             + 2 * mod)
            % mod;
        x = (x * mi(mul[i])) % mod;
    }
 
    // Comparing hash with hash of B
    if (x == hash_b)
        return true;
 
    return false;
}

int main()
{
    string a = "abbcacabbcab";
    string b = "abbca";

    int n,m;
    n=a.size();
    m=b.size();

    genHash(a, b);
    int cnt=0;
    for(int i=0;i<=n-m;i++)
    {
        checkEqual(i,n,m) && cnt++;
    }
    printf("Total %d matches found\n",cnt);
    return 0;
}