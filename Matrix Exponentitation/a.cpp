#include<bits/stdc++.h>
using namespace std;

struct Matrix
{
    double a[2][2]={{0,0},{0,0}};
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
    double p;
    scanf("%d %lf",&n,&p);
    Matrix f;
    f.a[0][0] = 1-p;
    f.a[0][1] = p;
    f.a[1][0] = p;
    f.a[1][1] = 1-p;
    f = expo_power(f, n);
    // double base[2][1]={{1},{0}};
    // base[0][0] = f.a[0][0]*base[0][0]+f.a[0][1]*base[1][0];
    // base[1][0] = f.a[1][0]*base[0][0]+f.a[1][1]*base[1][0];
    printf("%.10lf\n", f.a[0][0]);
    return 0;
}