#include <string>
#include "fixed_width.hpp"

fixed_width::fixed_width()
{

}

fixed_width::fixed_width(int mantissa, int exponet, int width)
{
    //int raw = pow(2, width);
    //int exp_size = std::log10<int>( raw );
    val = mantissa;
    val = mantissa << 12;
    val |= exponet & (0x000F | 0x0010 | 0x0020 | 0x0040 | 0x0080);
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
    return base_10_str;
}