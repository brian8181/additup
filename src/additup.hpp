#ifndef _additup_HPP
#define _additup_HPP

int add(int lhs, int rhs);
int subtract(int lhs, int rhs);
int multiply(int lhs, int rhs);
int divide(int dividend, int divisor);
int divide(int dividend, int divisor, /* out */ int& remainder);
long factorial(long x);
int pow_(int n, int pow);

double sin_(const double x);
double cos_(const double x);

int pi();
int e(long x);

#endif