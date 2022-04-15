#include<bits/stdc++.h>
using namespace std;

struct Matrix
{
    int a[3][3];
    Matrix()
    {
        for (size_t i = 0; i < 3; i++)
        {
            for (size_t j = 0; j < 3; j++)
            {
                a[i][j] = 0;
            }
        }
    }
    Matrix(int a[3][3])
    {
        for (size_t i = 0; i < 3; i++)
        {
            for (size_t j = 0; j < 3; j++)
            {
                this->a[i][j] = a[i][j];
            }
        }
    }
    Matrix operator*(const Matrix &other)
    {
        Matrix product;
        for (size_t i = 0; i < 3; i++)
        {
            for (size_t j = 0; j < 3; j++)
            {
                product.a[i][j] = 0;
                for (size_t k = 0; k < 3; k++)
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
    for (size_t i = 0; i < 3; i++)
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

// Equation: 
// f(n) = 2*f(n-1) + 3f(n-3)

int main()
{
    int matrix[3][3] = {{2, 0, 3}, {1, 0, 0}, {0, 1, 0}};
    Matrix f(matrix);

    int n;
    cin>>n;
    int base[3][1] = {{2}, {1}, {0}};
    f = expo_power(f, n - 2);
    base[0][0] = f.a[0][0]*base[0][0] + f.a[0][1]*base[1][0] + f.a[0][2]*base[2][0];
    base[1][0] = f.a[1][0]*base[0][0] + f.a[1][1]*base[1][0] + f.a[1][2]*base[2][0];
    base[2][0] = f.a[2][0]*base[0][0] + f.a[2][1]*base[1][0] + f.a[2][2]*base[2][0];
    cout<<base[0][0]<<endl;
    return 0;
}