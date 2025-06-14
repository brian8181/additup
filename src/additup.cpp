// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.

// License:    GPL
// Author:     Brian K Preston
// File Name:  additup.cpp
// Build Date: Tue Dec 26 07:35:13 AM CST 2023
// Version:    0.0.1

#include <iostream>
#include <string>
#include <getopt.h>
#include <fmt/format.h>
#include <cmath>
#include "bash_color.h"
#include "additup.hpp"

using namespace std;

//namespace add_it_up
//{

namespace aiu
{
int add(int lhs, int rhs)
{
	#ifndef NO_SHOW
	cout << "adding ... " << lhs << '+' << rhs << endl;
	#endif

	return lhs + rhs;
}

int subtract(int lhs, int rhs)
{
	return add(lhs, -rhs);
}

int multiply(int lhs, int rhs)
{
	int out = 0;
	for(int i = 0; i < rhs; ++i)
	{
		out = add(out, lhs);
	}
	return out;
}

int divide(int dividend, int divisor)
{
    int c = 1;
    int r = divisor;
    while(r < dividend)
    {
        r = add(r, divisor);
        c = add(c, 1);
    }
    if(r != dividend)
        --c;
    return c;
}

int divide(int dividend, int divisor, /* out */ int& remainder)
{
    int c = 1;
    int r = divisor;
    while(r < dividend)
    {
        r = add(r, divisor);
        c = add(c, 1);
    }
    remainder = dividend-r;
    if(remainder)
        --c;
    return c;
}

// int divide_v2(int dividend, int divisor)
// {
//     int c = 1;
//     int r = divisor;
//     // while(r < dividend)
//     // {
//     //     r = add(r, divisor);
//     //     c = add(c, 1);
//     // }
//     // if(r != dividend)
//     //     --c;
//     return c;
// }

int pow_(int n, int p)
{
	int out = n;
	for(int i = 0; i < (p-1); ++i)
	{
		out = multiply(out, n);
	}
	return out;
}

long factorial(long x)
{
    long product = 1;
    for(int i = 1; i < x+1; ++i)
    {
        product *= i;
    }
    return product;
}

double sin_(const double x)
{
    const int k = 15;   // iters
    double psum = 0; // partial sums
    for(int n = 0; n < k; ++n)
    {
        long s = (2.*n) + 1;
        long fac = factorial(s);
        psum += ( pow(-1, n) * pow(x, s) ) / fac;
    }
    return psum;
}

double sind_(const double x)
{
   return sin_(deg2rad(x));
}

double cos_(const double x)
{
    const int k = 15;   // iters
    double psum = 0; // partial sums
    for(int n = 0; n < k; ++n)
    {
        long s = (2*n);
        long fac = factorial(s);
        psum += ( pow(-1, n) * pow(x, s) ) / fac;
    }
    return psum;
}

double cosd_(const double x)
{
    return cos_(deg2rad(x));
}

double rad2deg(double radians)
{
    return (radians * (180/pi));
}

double deg2rad(double degrees)
{
    return (degrees * (pi/180));
}

double pi_()
{
	int k = 1;
    double sk = 0;
    long max = pow(2, 16);
    while(sk < max)
    {
        int top = pow(-1, k);
        int bot = add(multiply(2, k), 1);
        sk += multiply(top, divide(1,bot));
        ++k;
    }
    return sk;
}

double e_(long x)
{
	const int k = 15;   // iters
    double psum = 0; // partial sums
    for(int n = 0; n < k; ++n)
    {
        long fac = factorial(n);
        psum += ( pow(x, n) ) / fac;
    }
    return psum;
}

double ln_(long x)
{
    const int k = 15;   // iters
    double psum = 0; // partial sums
    for(int n = 0; n < k; ++n)
    {
        long fac = factorial(n);
        psum += ( pow(x, n) ) / fac;
    }
    return pow(psum, -1);
}

double ln_(double x)
{
    // from Wolfram ...
    // https://www.wolframalpha.com/input?i=ln

    // for abs(-1 + x)<1
    // log(x) = - sum_(k=1)^∞ ((-1)^k (-1 + x)^k)/k

    // for abs(-1 + x)>1
    // log(x) = log(-1 + x) - sum_(k=1)^∞ ((-1)^k (-1 + x)^(-k))/k

    const int k = 15;
    double psum = 0;

    if((x + -1) < 1)
    {
        for(int n = 0; n < k; ++n)
        {
            double term1 = (-1 + x);
            double numerator = pow(-1, n) * pow(term1, n);
            psum += numerator/n;
        }
        return psum;
    }
    else
    {
        for(int n = 0; n < k; ++n)
        {
            double term1 = (-1 + x);
            double numerator = pow(-1, n) * pow(term1, -n);
            psum += numerator/n;
        }
        return (ln_(-1 + x) - psum);
    }
    return 0;
}

double log_(long x)
{
    const int k = 15;   // iters
    double psum = 0; // partial sums
    for(int n = 0; n < k; ++n)
    {
        n *= n;
        psum += ( pow(x, n) ) / n;
    }
    return pow(psum, -1);
}

double log_(double base, double n)
{
    return (ln_(n) / ln_(base));
}
}

//}