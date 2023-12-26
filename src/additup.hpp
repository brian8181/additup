#ifndef _additup_HPP
#define _additup_HPP

#include "bgfloat.hpp"
#include "bgint.hpp"

int add(int lhs, int rhs);
int subtract(int lhs, int rhs);
int multiply(int lhs, int rhs);
int divide(int dividend, int divisor);
int divide(int dividend, int divisor, /* out */ int& remainder);
long factorial(long x);
int pow_(int n, int pow);

double rad2deg(double radians);
double deg2rad(double degrees);

double sin_(const double x);
double cos_(const double x);
double sind_(const double x);
double cosd_(const double x);

double pi_();
double e_(long x);
double ln_(long x);
double log_(long x);
double log_(bgfloat base, bgfloat n);


static const double pi = 3.141618;

#endif