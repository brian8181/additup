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

#ifndef _FIXED_WIDTH_HPP
#define _FIXED_WIDTH_HPP

using std::string;

class fixed_width 
{
public:
    fixed_width();
    fixed_width(int mantissa, int exponet, int width);
    fixed_width& add(fixed_width& lhs, fixed_width& rhs, /* out*/ fixed_width& output);
    fixed_width& add(fixed_width& lhs, short& rhs, /* out*/ fixed_width& output);
    fixed_width& add(const fixed_width& lhs, int& rhs, /* out*/ fixed_width& output);
    fixed_width& add(fixed_width& lhs, long& rhs, /* out*/ fixed_width& output);
    fixed_width& add(fixed_width& lhs, float& rhs, /* out*/ fixed_width& output);
    fixed_width& add(fixed_width& lhs, double& rhs, /* out*/ fixed_width& output);
    fixed_width divide(const fixed_width& rhs, const fixed_width& lhs, /* out*/ fixed_width& output);
    string to_str();

    //fixed_width& operator=(fixed_width& lhs);
    
    int get_mantissa();
    int get_exponet();
    long val = 0;
    int width = 4;
    string base_10_str;
    //std::mega m;
};

#endif