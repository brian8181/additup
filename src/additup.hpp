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

#ifndef _additup_HPP
#define _additup_HPP

#include "bgfloat.hpp"
#include "bgint.hpp"

namespace aiu
{

int add(int lhs, int rhs);
int subtract(int lhs, int rhs);
int multiply(int lhs, int rhs);
int divide(int dividend, int divisor);
int divide(int dividend, int divisor, /* out */ int& remainder);
long factorial(long x);
int pow_(int n, int pow);
int pow_(double n, int pow);

double rad2deg(double radians);
double deg2rad(double degrees);

double sin_(const double x);
double cos_(const double x);
double sind_(const double x);
double cosd_(const double x);

double pi_();
double e_(long x);
double ln_(long x); // natural
double ln_(double x); // natural
double log_(long x); // base 10
double log_(bgfloat base, bgfloat n);
double log_(double base, double n);

static const double pi = 3.141592653589793;
static const double e = 2.71828182846;


//static const double e = 2'7182'8182'8490; // 15 digits from 52 bits
//e=2.71828182845904523536028747135266249775724709369995957496696762772407663035...
//2.71828182845904

}

#endif