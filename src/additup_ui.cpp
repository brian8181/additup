/// This program is free software: you can redistribute it and/or modify
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
#include "bash_color.h"
#include "additup_ui.hpp"
#include "fixed_width.hpp"
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

	int dividend = 21;
	int divisor = 7;
	int quotient = divide(dividend, divisor);
	cout << dividend << "/" << divisor << "=" << quotient << endl;

	dividend = 25;
	divisor = 7;
	quotient = divide(dividend, divisor);
	cout << dividend << "/" << divisor << "=" << quotient << endl;

	dividend = 30;
	divisor = 7;
	int remainder = 0;
	quotient = divide(dividend, divisor, remainder);
	cout << dividend << "/" << divisor << "=" << quotient << " R=" << remainder << endl;

	dividend = 28;
	divisor = 7;
	remainder = 0;
	quotient = divide(dividend, divisor, remainder);
	cout << dividend << "/" << divisor << "=" << quotient << " R=" << remainder << endl;


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

	fixed_width fw(3141516, 1, 4);
	cout << "Fixed test: " << fw.to_str() << endl;

	double pi = 3.141618;

	//char degree_symb = (char)167;

	string s = fmt::format("Pi apporx. {0}", pi);
	cout << "format test: " << "Pi = " << s << endl;
	
	fixed_width splight(3000000, 7, 4);
	cout << "Speed of light: " << splight.to_str() << endl;

	double theta = 0;
	double sin_val = sin_(theta);
	cout << "sin( " <<  rad2deg(theta) << " ) = " << sin_val <<  endl;

	double cos_val = cos_(theta);
	cout << "cos( " <<  rad2deg(theta) << " ) = " << cos_val <<  endl;
	
	theta = pi/2;
	sin_val = sin_(theta);
	cout << "sin( " <<  rad2deg(theta) << " ) = " << sin_val <<  endl;

	cos_val = cos_(theta);
	cout << "cos( " <<  rad2deg(theta) << " ) = " << cos_val <<  endl;

	theta = pi;
	sin_val = sin_(theta);
	cout << "sin( " <<  rad2deg(theta) << " ) = " << sin_val <<  endl;

	cos_val = cos_(theta);
	cout << "cos( " <<  rad2deg(theta) << " ) = " << cos_val <<  endl;

	theta = pi/4;
	sin_val = sin_(theta);
	cout << "sin( " <<  rad2deg(theta) << " ) = " << sin_val <<  endl;

	cos_val = cos_(theta);
	cout << "cos( " <<  rad2deg(theta) << " ) = " << cos_val <<  endl;

	theta = pi/6;
	sin_val = sin_(theta);
	cout << "sin( " <<  rad2deg(theta) << " ) = " << sin_val <<  endl;

	cos_val = cos_(theta);
	cout << "cos( " <<  rad2deg(theta) << " ) = " << cos_val <<  endl;

	theta = 2.*(pi/6);
	sin_val = sin_(theta);
	cout << "sin( " <<  rad2deg(theta) << " ) = " << sin_val <<  endl;

	cos_val = cos_(theta);
	cout << "cos( " <<  rad2deg(theta) << " ) = " << cos_val <<  endl;

	double exp_val = e_(1);
	cout << "exp( " << 1 << " ) = " << exp_val << endl;

	double ln_val = ln_(exp_val);
	cout << "ln( " << exp_val << " ) = " << ln_val << endl;

	exp_val = e_(pi);
	cout << "exp( " << pi << " ) = " << exp_val << endl; 

	exp_val = e_(2);
	cout << "exp( " << 2 << " ) = " << exp_val << endl; 

	ln_val = ln_(10);
	cout << "ln( " << 10 << " ) = " << ln_val << endl;

	double log_val = log_(1000);
	cout << "ln( " << 1000 << " ) = " << log_val << endl;
	

	return 0;
}
