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
// File Name:  complex.hpp
// Build Date: Tue Dec 26 07:35:13 AM CST 2023
// Version:    0.0.1

#ifndef _COMPLEX_HPP
#define _COMPLEX_HPP

#include <string>
#include <cmath>
#include <ratio>
#include "additup.hpp"

// complex integer
class complex_int
{
public:
    complex_int(int real, int imag);
    complex_int& add(const complex_int& a);
    complex_int& multiply(const complex_int& a);
    static complex_int& add(const int& a, const complex_int& b, /* out */ complex_int& r);
    static complex_int& add(const complex_int& a, const complex_int& b, /* out */ complex_int& r);
    static complex_int& multiply(int a, complex_int& b);
    static complex_int& multiply(const complex_int a, const complex_int& b);
   
    friend complex_int& operator*(const complex_int& a, const complex_int& b)
    {
        return multiply(a, b);
    }

    // complex_int& operator+(const complex_int& that)
    // {
    //      r = add(*this, that);
    //     return add(*this, that);
    // }
    
    int get_real();
    int get_imag();
    
private:
    int real;
    int imag;
};

#endif