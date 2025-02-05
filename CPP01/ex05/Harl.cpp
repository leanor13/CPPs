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
	// we create those arrays once and don't recreate them every time complain is called
    static const std::string levels[4] = { "DEBUG", "INFO", "WARNING", "ERROR" };
    static void (Harl::*funcPtr[4])() = { &Harl::debug, &Harl::info, &Harl::warning, &Harl::error };

    for (int i = 0; i < 4; i++) {
        if (levels[i] == level) {
            (this->*funcPtr[i])();
            return;
        }
    }
}