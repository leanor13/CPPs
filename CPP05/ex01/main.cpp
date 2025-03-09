#include "Bureaucrat.hpp"
#include "Form.hpp"

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
        Bureaucrat b2("Bob", 1500);
        std::cout << b2 << std::endl;
        b2.decrementGrade();
    }
    catch (const std::exception& e) {
        std::cerr << "Exception(expected): " << e.what() << std::endl;
    }

    try {
        Bureaucrat b3("Charlie", -10);
    }
    catch (const std::exception& e) {
        std::cerr << "Exception(expected): " << e.what() << std::endl;
    }

    try {
        Bureaucrat alice("Alice", 2);
        Form contract("Contract", 3, 5);

        std::cout << contract << std::endl;
        alice.signForm(contract);
        std::cout << contract << std::endl;

        Bureaucrat bob("Bob", 150);
        Form report("Report", 50, 100);
        bob.signForm(report);  // Here we expect exception
        std::cout << report << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }


    return 0;
}
