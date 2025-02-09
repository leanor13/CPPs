#include "Harl.hpp"
#include <iostream>

void Harl::debug() {
	std::cout << "[DEBUG] This is a debug message." << std::endl;
}

void Harl::info() {
	std::cout << "[INFO] This is an info message." << std::endl;
}

void Harl::warning() {
	std::cout << "[WARNING] This is a warning message." << std::endl;
}

void Harl::error() {
	std::cout << "[ERROR] This is an error message." << std::endl;
}

void Harl::complain(std::string level) {
    static const std::string levels[4] = { "DEBUG", "INFO", "WARNING", "ERROR" };
    static void (Harl::*funcPtr[4])() = { &Harl::debug, &Harl::info, &Harl::warning, &Harl::error };

    int index = -1;
    for (int i = 0; i < 4; i++) {
        if (levels[i] == level) {
            index = i;
            break;
        }
    }

    switch (index) {
        case 0:
            (this->*funcPtr[0])();
            // fallthrough
        case 1:
            (this->*funcPtr[1])();
            // fallthrough
        case 2:
            (this->*funcPtr[2])();
            // fallthrough
        case 3:
            (this->*funcPtr[3])();
            break;
        default:
            std::cerr << "Unknown log level" << std::endl;
            break;
    }
}
