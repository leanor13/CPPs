#include <iostream>
#include <limits>  // Для крайних значений
#include "Fixed.hpp"

int main() {
    std::cout << "\n=== Tests from PDF ===" << std::endl;
    Fixed a;
    Fixed const b(10);
    Fixed const c(42.42f);
    Fixed const d(b);
    a = Fixed(1234.4321f);

    std::cout << "a is " << a << std::endl;
    std::cout << "b is " << b << std::endl;
    std::cout << "c is " << c << std::endl;
    std::cout << "d is " << d << std::endl;

    std::cout << "a is " << a.toInt() << " as integer" << std::endl;
    std::cout << "b is " << b.toInt() << " as integer" << std::endl;
    std::cout << "c is " << c.toInt() << " as integer" << std::endl;
    std::cout << "d is " << d.toInt() << " as integer" << std::endl;

    std::cout << "\n=== Additional Tests ===" << std::endl;

    // 1. min and max values
    Fixed maxInt(std::numeric_limits<int>::max());  // INT_MAX (8388607.99)
    Fixed minInt(std::numeric_limits<int>::min());  // INT_MIN (-8388608)
    Fixed maxFloat(std::numeric_limits<float>::max()); // FLT_MAX (8388607.99)
    Fixed minFloat(std::numeric_limits<float>::min()); // FLT_MIN (very small value)
    Fixed trueMinFloat(std::numeric_limits<float>::denorm_min()); // FLT_TRUE_MIN
    Fixed negativeFloat(-1234.5678f);  // negative float
    Fixed negativeMinFloat(-std::numeric_limits<float>::min()); // -FLT_MIN
    Fixed negativeTrueMinFloat(-std::numeric_limits<float>::denorm_min()); // -FLT_TRUE_MIN
    Fixed negativeMaxFloat(-std::numeric_limits<float>::max()); // -FLT_MAX


    // 3. show results
    std::cout << "INT_MAX = " << maxInt << std::endl;
    std::cout << "INT_MIN = " << minInt << std::endl;
    std::cout << "FLT_MAX = " << maxFloat << std::endl;
    std::cout << "FLT_MIN = " << minFloat << std::endl;
    std::cout << "FLT_TRUE_MIN = " << trueMinFloat << std::endl;
    std::cout << "-FLT_MIN = " << negativeMinFloat << std::endl;
    std::cout << "-FLT_TRUE_MIN = " << negativeTrueMinFloat << std::endl;
    std::cout << "-FLT_MAX = " << negativeMaxFloat << std::endl;
    
    std::cout << "Negative float = " << negativeFloat << std::endl;
    

    std::cout << "\n=== toInt() Tests ===" << std::endl;
    std::cout << "c.toInt() = " << c.toInt() << std::endl;
    std::cout << "negativeFloat.toInt() = " << negativeFloat.toInt() << std::endl;

    std::cout << "\n=== Assignment Operator Test ===" << std::endl;
    Fixed f;
    f = c;
    std::cout << "f = " << f << std::endl;

    return 0;
}
