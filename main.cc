#include <iostream>
#include "rational.hpp"

int main()
{
    Rational m(3,4);
    Rational k(2,7);
    Rational d(1,1);
    std::cout << k.numerator() << "/" << k.denominator() << std::endl;
    k = k + 2;
    std::cout << k << std::endl;
    return 0;
}