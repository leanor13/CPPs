#include <iostream>
#include <limits>
#include "Fixed.hpp"

void testComparisons() {
    std::cout << "\n=== Comparison Operators ===" << std::endl;
    Fixed a(42);
    Fixed b(42);
    Fixed c(100);

    std::cout << "a == b: " << (a == b) << std::endl;
    std::cout << "a != c: " << (a != c) << std::endl;
    std::cout << "a < c: " << (a < c) << std::endl;
    std::cout << "c > a: " << (c > a) << std::endl;
    std::cout << "a <= b: " << (a <= b) << std::endl;
    std::cout << "c >= a: " << (c >= a) << std::endl;
}

void testArithmetic() {
    std::cout << "\n=== Arithmetic Operators ===" << std::endl;
    Fixed a(10);
    Fixed b(2);

    std::cout << "a + b = " << (a + b) << std::endl;
    std::cout << "a - b = " << (a - b) << std::endl;
    std::cout << "a * b = " << (a * b) << std::endl;
    std::cout << "a / b = " << (a / b) << std::endl;
}

void testIncrementDecrement() {
    std::cout << "\n=== Increment/Decrement Operators ===" << std::endl;
    Fixed a;

    std::cout << "a = " << a << std::endl;
    std::cout << "++a = " << ++a << std::endl;
    std::cout << "a++ = " << a++ << std::endl;
    std::cout << "a = " << a << std::endl;
    std::cout << "--a = " << --a << std::endl;
    std::cout << "a-- = " << a-- << std::endl;
    std::cout << "a = " << a << std::endl;
}

void testMinMax() {
    std::cout << "\n=== Min/Max Functions ===" << std::endl;
    Fixed a(3.14f);
    Fixed b(2.71f);

    std::cout << "min(a, b) = " << Fixed::min(a, b) << std::endl;
    std::cout << "max(a, b) = " << Fixed::max(a, b) << std::endl;

    const Fixed c(5.5f);
    const Fixed d(10.1f);
    
    std::cout << "min(c, d) = " << Fixed::min(c, d) << std::endl;
    std::cout << "max(c, d) = " << Fixed::max(c, d) << std::endl;
}

void testEdgeCases() {
    std::cout << "\n=== Edge Cases ===" << std::endl;

    Fixed maxFixed(std::numeric_limits<int>::max()); // INT_MAX
    Fixed minFixed(std::numeric_limits<int>::min()); // INT_MIN
    Fixed zero(0);
    Fixed one(1);

    std::cout << "INT_MAX = " << maxFixed << std::endl;
    std::cout << "INT_MIN = " << minFixed << std::endl;
    std::cout << "zero = " << zero << std::endl;
    
    std::cout << "maxFixed + one = " << (maxFixed + one) << std::endl;
    std::cout << "minFixed - one = " << (minFixed - one) << std::endl;

    std::cout << "zero / zero (should error) = " << (zero / zero) << std::endl;
    std::cout << "zero / one = " << (zero / one) << std::endl;
    std::cout << "one / zero (should error) = " << (one / zero) << std::endl;
}

int main(void) {
    Fixed a;
    Fixed const b(Fixed(5.05f) * Fixed(2));

    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;

    std::cout << b << std::endl;

    std::cout << Fixed::max(a, b) << std::endl;

    testComparisons();
    testArithmetic();
    testIncrementDecrement();
    testMinMax();
    testEdgeCases();

    return 0;
}
