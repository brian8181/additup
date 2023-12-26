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