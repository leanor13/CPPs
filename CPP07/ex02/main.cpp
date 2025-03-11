#include "Array.hpp"

void testIntArray() {
    std::cout << "===== Testing with int array =====" << std::endl;
    Array<int> arr(5);
    for (size_t i = 0; i < arr.size(); i++)
        arr[i] = static_cast<int>(i) * 2;

    for (size_t i = 0; i < arr.size(); i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
}

void testStringArray() {
    std::cout << "\n===== Testing with string array =====" << std::endl;
    Array<std::string> strArr(3);
    strArr[0] = "Hello";
    strArr[1] = "World";
    strArr[2] = "42";

    for (size_t i = 0; i < strArr.size(); i++)
        std::cout << strArr[i] << " ";
    std::cout << std::endl;
}

void testCopyAndAssignment() {
    std::cout << "\n===== Testing copy constructor and assignment =====" << std::endl;
    Array<int> a(3);
    a[0] = 10;
    a[1] = 20;
    a[2] = 30;

    Array<int> b(a);
    Array<int> c;
    c = a;

    b[1] = 99;
    c[2] = 77;

    std::cout << "Original: ";
    for (size_t i = 0; i < a.size(); i++) std::cout << a[i] << " ";
    std::cout << "\nCopy: ";
    for (size_t i = 0; i < b.size(); i++) std::cout << b[i] << " ";
    std::cout << "\nAssigned: ";
    for (size_t i = 0; i < c.size(); i++) std::cout << c[i] << " ";
    std::cout << std::endl;
}

void testOutOfBounds() {
    std::cout << "\n===== Testing out-of-bounds access =====" << std::endl;
    try {
        Array<int> arr(2);
        std::cout << arr[5] << std::endl; // getting outside of array limits
    } catch (const std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
}

int main() {
    testIntArray();
    testStringArray();
    testCopyAndAssignment();
    testOutOfBounds();
    return 0;
}
