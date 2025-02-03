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

#include <string>
#include <sstream>
#include "fixed_width.hpp"

fixed_width::fixed_width()
{

}

fixed_width::fixed_width(int mantissa, int exponet, int width)
{
    val = mantissa << 8;
    val |= (exponet & 0x000000FF);
}

fixed_width& fixed_width::add(const fixed_width& rhs, int& lhs, /* out*/ fixed_width& output)
{

    // output = rhs.get_mantissa();
    // output = output + lhs;
    return output;
}

fixed_width& fixed_width::add(fixed_width& lhs, long& rhs, /* out*/ fixed_width& output)
{
    return output;
}

fixed_width& fixed_width::add(fixed_width& lhs, short& rhs, /* out*/ fixed_width& output)
{
    return output;
}

fixed_width& fixed_width::add(fixed_width& lhs, float& rhs, /* out*/ fixed_width& output)
{
    return output;
}

fixed_width& fixed_width::add(fixed_width& lhs, double& rhs, /* out*/ fixed_width& output)
{
    return output;
}

fixed_width& fixed_width::add(fixed_width& lhs, fixed_width& rhs, /* out*/ fixed_width& output)
{
    // int ret = lhs.get_mantissa() + rhs.get_mantissa();
    // output = fixed_width(ret, lhs.get_exponet(), 4);
    return output;
}

fixed_width fixed_width::divide(const fixed_width& lhs, const fixed_width& rhs, /* out*/ fixed_width& output)
{
    output = rhs;
    return output;
}

int fixed_width::get_mantissa()
{
    return val >> 8;
}

int fixed_width::get_exponet()
{
    return  val & 0x000000FF;  
}

string fixed_width::to_str()
{
    int exponet = (val & 0x000000FF);
    int mantissa = (val >> 8);
    base_10_str.clear();
    base_10_str = std::to_string(mantissa);
    base_10_str.length();
    size_t sz = base_10_str.length();
    size_t sig_size = exponet;
    if(sig_size < sz) 
    {
        base_10_str.insert(exponet, ".");
        base_10_str.erase(exponet+width+1);
    }
    return base_10_str;
}