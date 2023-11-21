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
// File Name:  additup.hpp
// Build Date: Tue Nov 21 04:38:53 PM CST 2023
// Version:    3.6.7

#ifndef _additup_HPP
#define _additup_HPP

#include <string>

using std::string;

void print_help();
void print_match_header(const string& pattern, const string& src, const bool single_flag, const bool pretty_flag);
int parse_options(int argc, char* argv[]);

int add(int lhs, int rhs);
int multiply(int lhs, int rhs);
int pow(int n, int pow);

int pi();
int e();

#endif
