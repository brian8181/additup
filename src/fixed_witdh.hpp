#ifndef _FIXED_WIDTH_HPP
#define _FIXED_WIDTH_HPP

#include <string>
#include <cmath>
#include "additup.hpp"

using std::string;

class fixed_width 
{
public:
    fixed_width(int width)
    {
        int raw = pow(2, width);
        int exp_size = std::log10<int>( raw );

    }

    string to_str()
    {
        return base_10_str;
    }

    long val = 0;
    int width = 4;
    string base_10_str = "0";
}

#endif