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
    fixed_width(int mantissa, int exponet, int width)
    {
        int raw = pow(2, width);
        int exp_size = std::log10<int>( raw );
        val = mantissa;
        val = mantissa << 12;
        val |= exponet & (0x000F | 0x0010 | 0x0020 | 0x0040 | 0x0080);

    }

    fixed_width& add(const fixed_width& rhs, const fixed_width& lhs, /* out*/ fixed_width& output)
    {
        return output;
    }

    fixed_width& add(const fixed_width& rhs, const fixed_width& lhs, /* out*/ fixed_width& output)
    {
        return output;
    }

    fixed_width divide(const fixed_width& rhs, const fixed_width& lhs, /* out*/ fixed_width& output)
    {
        output = rhs;
        return output;
    }

    string to_str()
    {
        return base_10_str;
    }

    long val = 0;
    int width = 4;
    string base_10_str = "0";
    std::mega m;
};

#endif