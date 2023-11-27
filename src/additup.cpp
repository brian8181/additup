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

int parse_options(int argc, char* argv[])
{
	cout << FMT_FG_BLUE << "Hello World!"  << FMT_RESET << endl;
	cout << FMT_FG_RED << "Hello World!"  << FMT_RESET << endl;
	cout << FMT_FG_GREEN << "Hello World!"  << FMT_RESET << endl;
	cout << FMT_FG_YELLOW << "Hello World!"  << FMT_RESET << endl;

	int lhs = 2;
	int rhs = 3;
	int ans = 0;

	ans = add(lhs, rhs);
	cout << lhs << '+' << rhs << "=" << ans << endl;

	ans = subtract(lhs, rhs);
	cout << lhs << '-' << rhs << "=" << ans << endl;

	ans = multiply(lhs, rhs);
	cout << lhs << '*' << rhs << "=" << ans << endl;

	lhs = 3;
	rhs = 7;
	ans = multiply(lhs, rhs);
	cout << lhs << '*' << rhs << "=" << ans << endl;

	int n = 0;
	int p = 0;

	n = 2;
	p = 3;
	ans = pow(n, p);
	cout << n << '^' << p << "=" << ans << endl;

	n = 3;
	p = 4;
	ans = pow(n, p);
	cout << n << '^' << p << "=" << ans << endl;

	return 0;
}

int add(int lhs, int rhs)
{
	#ifndef NO_SHOW
	cout << "adding ... " << lhs << '+' << rhs << endl;
	#endif
	
	return lhs + rhs;
}

int subtract(int lhs, int rhs)
{
	add(lhs, -rhs);
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