#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (n); i++)

struct Matrix
{
    int a[2][2] = {{0, 0}, {0, 0}};
    Matrix operator*(const Matrix &other)
    {
        Matrix product;
        for (size_t i = 0; i < 2; i++)
        {
            for (size_t j = 0; j < 2; j++)
            {
                product.a[i][j] = 0;
                for (size_t k = 0; k < 2; k++)
                {
                    product.a[i][j] += a[i][k] * other.a[k][j];
                }
            }
        }
        return product;
    }
};

Matrix expo_power(Matrix a, int k)
{
    Matrix product;
    for (size_t i = 0; i < 2; i++)
    {
        product.a[i][i] = 1; // Initialize the identity matrix
    }    
    while (k > 0)
    {
        if (k % 2)
        {
            product = product * a;
        }
        a = a * a;
        k /= 2;
    }
    return product;
}

int main()
{
    int n;
    cin >> n;
    Matrix f;
    f.a[0][0] = 1;
    f.a[0][1] = 1;
    f.a[1][0] = 1;
    f.a[1][1] = 0;
    f = expo_power(f, n - 1);
    cout << f.a[0][0] << endl;
    return 0;
}