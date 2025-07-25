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
// File Name:  complex.cpp
// Build Date: Tue Dec 26 07:35:13 AM CST 2023
// Version:    0.0.1

#include "complex.hpp"

complex_int::complex_int(int real, int imag)
{
    this->real = real;
    this->imag = imag;
}

complex_int& complex_int::add(const int& a, const complex_int& b, /* out */ complex_int& r)
{
    r = complex_int((a + b.real), b.imag);
    return r;
}

complex_int& complex_int::add(const complex_int& a, const complex_int& b, /* out */ complex_int& r)
{
    r = complex_int((a.real + b.real), (a.imag + b.imag));
    return r;
}

complex_int& complex_int::multiply(int a, complex_int& b)
{
    complex_int ret (a*b.get_real(), a*b.get_imag());
    b = ret;
    return b;
}

// complex_int& complex_int::multiply(complex_int a, complex_int& b)
// {
//     complex_int ret = add(multiply(a.get_real(), b), multiply(a.get_imag(), b));
//     b = ret;
//     return ret;
// }

int complex_int::get_real()
{
    return real;
}

int complex_int::get_imag()
{
    return imag;
}