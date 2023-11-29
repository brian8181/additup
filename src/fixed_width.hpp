#ifndef _FIXED_WIDTH_HPP
#define _FIXED_WIDTH_HPP

#include <string>
#include <cmath>
#include <ratio>
#include "additup.hpp"

using std::string;

class fixed_width 
{
public:
    fixed_width();
    fixed_width(int mantissa, int exponet, int width);
    fixed_width& add(const fixed_width& rhs, const fixed_width& lhs, /* out*/ fixed_width& output);
    fixed_width& add(const fixed_width& rhs, const int& lhs, /* out*/ fixed_width& output);
    fixed_width divide(const fixed_width& rhs, const fixed_width& lhs, /* out*/ fixed_width& output);
    string to_str();
    

    long val = 0;
    int width = 4;
    string base_10_str;
    std::mega m;
};

#endif