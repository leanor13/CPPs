#include "Bureaucrat.hpp"

int main() {
    Bureaucrat b1("Alice", 2);
    try {
        std::cout << b1 << std::endl;
        b1.incrementGrade();
        std::cout << b1 << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "Exception(not expected): " << e.what() << std::endl;
    }

    try {
        b1.incrementGrade();
    }
    catch (const std::exception& e) {
        std::cerr << "Exception(expected): " << e.what() << std::endl;
    }

    try {
        Bureaucrat b2("Bob", 150);
        std::cout << b2 << std::endl;
        b2.decrementGrade();
    }
    catch (const std::exception& e) {
        std::cerr << "Exception(expected): " << e.what() << std::endl;
    }

    try {
        Bureaucrat b3("Charlie", 0);
    }
    catch (const std::exception& e) {
        std::cerr << "Exception(expected): " << e.what() << std::endl;
    }

    return 0;
}
