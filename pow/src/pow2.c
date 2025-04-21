#include <stdio.h>

// Taylor series for natural log ln(x), valid for 0.5 < x < 1.5
double ln(double x)
{
    if (x <= 0) return 0;  // ln undefined for <= 0
    double y = (x - 1) / (x + 1);
    double y2 = y * y;
    double result = 0.0;
    double term = y;
    int i;

    for (i = 1; i < 100; i += 2)
	{
        result += term / i;
        term *= y2;
    }

    return 2 * result;
}

// Taylor series for exp(x)
double exp_taylor(double x)
{
    double sum = 1.0;  // First term of series
    double term = 1.0;
    for (int i = 1; i < 50; i++)
	{
        term *= x / i;
        sum += term;
    }
    return sum;
}

// Real power a^b = exp(b * ln(a))
double real_pow(double a, double b)
{
    if (a <= 0) return 0; // ln(a) undefined
    double log_a = ln(a);
    double exp_result = exp_taylor(b * log_a);
    return exp_result;
}

// int main()
// {
//     double a = 5.0;
//     double b = 1.414;  // approx sqrt(2)

//     double result = real_pow(a, b);
//     printf("%f^%f = %f\n", a, b, result);
//     return 0;
// }
