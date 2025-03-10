#include "iter.hpp"

void increment(int& n) {
    n++;
}

void toUpper(char& c) {
    if (c >= 'a' && c <= 'z')
        c = c - ('a' - 'A');
}

void printInt(int& n) {
    std::cout << n << " ";
}

void printChar(char& c) {
    std::cout << c << " ";
}

int main() {
    std::cout << "===== Testing with int array =====" << std::endl;
    int arr[] = {1, 2, 3, 4, 5};
    iter(arr, 5, printInt);
    std::cout << std::endl;

    iter(arr, 5, increment);
    iter(arr, 5, printInt);
    std::cout << std::endl;

    std::cout << "\n===== Testing with char array =====" << std::endl;
    char str[] = "hello";
    iter(str, 5, printChar);
    std::cout << std::endl;

    iter(str, 5, toUpper);
    iter(str, 5, printChar);
    std::cout << std::endl;

    std::cout << "\n===== Testing with empty array =====" << std::endl;
    int emptyArr[0];
    iter(emptyArr, 0, printInt); // should not print anything
    std::cout << "[Empty Test Completed]" << std::endl;

    std::cout << "\n===== Testing with nullptr =====" << std::endl;
    int* nullArr = nullptr;
    iter(nullArr, 5, printInt);  // should not print anything
    std::cout << "[Nullptr Test Completed]" << std::endl;

    return 0;
}
