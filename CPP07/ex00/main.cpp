#include "whatever.hpp"
#include <iostream>

struct TestStruct {
    int value;
    TestStruct(int v) : value(v) {}

    bool operator<(const TestStruct& other) const { return value < other.value; }
    bool operator>(const TestStruct& other) const { return value > other.value; }
};

std::ostream& operator<<(std::ostream& os, const TestStruct& ts) {
    os << ts.value;
    return os;
}

int main() {
    std::cout << "===== Testing with int =====" << std::endl;
    int a = 2, b = 3;
    ::swap(a, b);
    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "min(a, b) = " << ::min(a, b) << std::endl;
    std::cout << "max(a, b) = " << ::max(a, b) << std::endl;

    std::cout << "\n===== Testing with double =====" << std::endl;
    double x = 4.5, y = 2.3;
    ::swap(x, y);
    std::cout << "x = " << x << ", y = " << y << std::endl;
    std::cout << "min(x, y) = " << ::min(x, y) << std::endl;
    std::cout << "max(x, y) = " << ::max(x, y) << std::endl;

    std::cout << "\n===== Testing with char =====" << std::endl;
    char c1 = 'A', c2 = 'Z';
    ::swap(c1, c2);
    std::cout << "c1 = " << c1 << ", c2 = " << c2 << std::endl;
    std::cout << "min(c1, c2) = " << ::min(c1, c2) << std::endl;
    std::cout << "max(c1, c2) = " << ::max(c1, c2) << std::endl;

    std::cout << "\n===== Testing with std::string =====" << std::endl;
    std::string s1 = "chaine1", s2 = "chaine2";
    ::swap(s1, s2);
    std::cout << "s1 = " << s1 << ", s2 = " << s2 << std::endl;
    std::cout << "min(s1, s2) = " << ::min(s1, s2) << std::endl;
    std::cout << "max(s1, s2) = " << ::max(s1, s2) << std::endl;

    std::cout << "\n===== Testing with custom struct =====" << std::endl;
    TestStruct obj1(10), obj2(20);
    ::swap(obj1, obj2);
    std::cout << "obj1 = " << obj1 << ", obj2 = " << obj2 << std::endl;
    std::cout << "min(obj1, obj2) = " << ::min(obj1, obj2) << std::endl;
    std::cout << "max(obj1, obj2) = " << ::max(obj1, obj2) << std::endl;

    return 0;
}