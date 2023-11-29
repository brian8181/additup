#include <string>
#include <sstream>
#include "fixed_width.hpp"

fixed_width::fixed_width()
{

}

fixed_width::fixed_width(int mantissa, int exponet, int width)
{
    int raw = pow(2, width);
    int exp_size = std::log10<int>( raw );
    val = mantissa << 8;
    val |= (exponet & 0x000000FF);
}

fixed_width& fixed_width::add(const fixed_width& rhs, const int& lhs, /* out*/ fixed_width& output)
{
    return output;
}

fixed_width& fixed_width::add(const fixed_width& rhs, const fixed_width& lhs, /* out*/ fixed_width& output)
{
    return output;
}

fixed_width fixed_width::divide(const fixed_width& rhs, const fixed_width& lhs, /* out*/ fixed_width& output)
{
    output = rhs;
    return output;
}

string fixed_width::to_str()
{
    int exponet = (val & 0x000000FF);
    int mantissa = (val >> 8);
    base_10_str.clear();
    base_10_str = std::to_string(mantissa);
    int len = base_10_str.size();
    base_10_str.insert(exponet, ".");
    base_10_str.erase(exponet+width);
    return base_10_str;
}