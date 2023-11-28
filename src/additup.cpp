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
// Build Date: Tue Nov 21 04:38:53 PM CST 2023
// Version:    3.6.7

#include <iostream>
#include <string>
#include <getopt.h>
#include "bash_color.h"
#include "additup.hpp"

using namespace std;

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

int pow(int n, int p)
{
	int out = n;
	for(int i = 0; i < (p-1); ++i)
	{
		out = multiply(out, n);
	}
	return out;
}

int pi()
{
	// todo
	return 0;
}

int e()
{
	// todo

	return 0;
}