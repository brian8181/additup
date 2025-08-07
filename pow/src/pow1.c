#include <stdio.h>

/* Integer power: a^n */
double int_pow(double base, int exp)
{
    double result = 1.0;
    for (int i = 0; i < exp; i++)
    {
        result *= base;
    }
    return result;
}

/* Nth root using binary search */
double nth_root(double x, int n)
{
    double low = 0, high = x, mid;
    double eps = 1e-7;

    if (x < 1.0) high = 1.0;

    while ((high - low) > eps)
    {
        mid = (low + high) / 2.0;
        if (int_pow(mid, n) < x)
            low = mid;
        else
            high = mid;
    }
    return (low + high) / 2.0;
}

/* */
/* a^(m/n) */
double fractional_pow(double a, int m, int n)
{
    double powered = int_pow(a, m);      // a^m
    return nth_root(powered, n);         // (a^m)^(1/n)
}

// int main()
// {
//     double a = 9.0;
//     int m = 1;
//     int n = 2;

//     double result = fractional_pow(a, m, n); // computes sqrt(9)
//     printf("%f^%d/%d = %f\n", a, m, n, result); // should print 3.000...
//     return 0;
// }
