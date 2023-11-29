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

fixed_width& fixed_width::add(fixed_width& rhs, int& lhs, /* out*/ fixed_width& output)
{
    //output = rhs.get_mantissa() + lhs;
    return output;
}

fixed_width& fixed_width::add(fixed_width& rhs, fixed_width& lhs, /* out*/ fixed_width& output)
{
    int ret = rhs.get_mantissa() + lhs.get_mantissa();
    output = fixed_width(ret, rhs.get_exponet(), 4);
    return output;
}

fixed_width fixed_width::divide(const fixed_width& rhs, const fixed_width& lhs, /* out*/ fixed_width& output)
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
    base_10_str.insert(exponet, ".");
    base_10_str.erase(exponet+width+1);
    return base_10_str;
}