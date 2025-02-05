#include "Harl.hpp"
#include <iostream>

int main() {
    Harl harl;

    std::cout << "\n== Test 1: Valid Levels ==" << std::endl;
    std::cout << "[Expected] DEBUG: Detailed debug message" << std::endl;
    harl.complain("DEBUG");

    std::cout << "[Expected] INFO: Informational message" << std::endl;
    harl.complain("INFO");

    std::cout << "[Expected] WARNING: Warning message" << std::endl;
    harl.complain("WARNING");

    std::cout << "[Expected] ERROR: Critical error message" << std::endl;
    harl.complain("ERROR");

    std::cout << "\n== Test 2: Invalid Levels ==" << std::endl;
    std::cout << "[Expected] (no output, invalid level)" << std::endl;
    harl.complain("UNKNOWN");

    std::cout << "[Expected] (no output, invalid level)" << std::endl;
    harl.complain("");

    return 0;
}
