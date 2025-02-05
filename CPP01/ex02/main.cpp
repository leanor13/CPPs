#include <iostream>

int main() {
    std::string str = "HI THIS IS BRAIN";

    std::string* stringPTR = &str;
    std::string& stringREF = str;

    // addresses
    std::cout << "Address of str      : " << &str << std::endl;
    std::cout << "Address held by PTR : " << stringPTR << std::endl;
    std::cout << "Address held by REF : " << &stringREF << std::endl;

    // values
    std::cout << "Value of str        : " << str << std::endl;
    std::cout << "Value pointed by PTR: " << *stringPTR << std::endl;
    std::cout << "Value in REF        : " << stringREF << std::endl;

    return 0;
}
