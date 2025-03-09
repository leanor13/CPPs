#include "ScalarConverter.hpp"

// Constructor, copy constructor, assignment operator, and destructor are private
ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter&) {}
ScalarConverter& ScalarConverter::operator=(const ScalarConverter&) { return *this; }
ScalarConverter::~ScalarConverter() {}

// Function to determine the type and convert it
void ScalarConverter::convert(const std::string& literal) {
    if (isChar(literal)) {
        printChar(literal[0]);
    } else if (isInt(literal)) {
        int value = std::atoi(literal.c_str());
        printInt(value);
    } else if (isFloat(literal)) {
        float value = std::atof(literal.c_str());
        printFloat(value);
    } else if (isDouble(literal)) {
        double value = std::strtod(literal.c_str(), NULL);
        printDouble(value);
    } else {
        std::cout << "Invalid input: conversion impossible" << std::endl;
    }
}

// Helper functions to determine the type
bool ScalarConverter::isChar(const std::string& str) {
    return str.length() == 1 && std::isprint(str[0]) && !std::isdigit(str[0]);
}

bool ScalarConverter::isInt(const std::string& str) {
    char* end;
    long value = std::strtol(str.c_str(), &end, 10);
    return *end == '\0' && value >= std::numeric_limits<int>::min() && value <= std::numeric_limits<int>::max();
}

bool ScalarConverter::isFloat(const std::string& str) {
    char* end;
    std::strtof(str.c_str(), &end);
    return *end == 'f' && *(end + 1) == '\0';
}

bool ScalarConverter::isDouble(const std::string& str) {
    char* end;
    std::strtod(str.c_str(), &end);
    return *end == '\0';
}

// Print functions
void ScalarConverter::printChar(char c) {
    std::cout << "char: '" << c << "'" << std::endl;
    std::cout << "int: " << static_cast<int>(c) << std::endl;
    std::cout << "float: " << static_cast<float>(c) << "f" << std::endl;
    std::cout << "double: " << static_cast<double>(c) << std::endl;
}

void ScalarConverter::printInt(int n) {
    if (n < 32 || n > 126)
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: '" << static_cast<char>(n) << "'" << std::endl;

    std::cout << "int: " << n << std::endl;
    std::cout << "float: " << static_cast<float>(n) << "f" << std::endl;
    std::cout << "double: " << static_cast<double>(n) << std::endl;
}

void ScalarConverter::printFloat(float f) {
    if (f < 32 || f > 126 || std::isnan(f))
        std::cout << "char: impossible" << std::endl;
    else
        std::cout << "char: '" << static_cast<char>(f) << "'" << std::endl;

    if (f < std::numeric_limits<int>::min() || f > std::numeric_limits<int>::max() || std::isnan(f))
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(f) << std::endl;

    std::cout << "float: " << f << "f" << std::endl;
    std::cout << "double: " << static_cast<double>(f) << std::endl;
}

void ScalarConverter::printDouble(double d) {
    if (d < 32 || d > 126 || std::isnan(d))
        std::cout << "char: impossible" << std::endl;
    else
        std::cout << "char: '" << static_cast<char>(d) << "'" << std::endl;

    if (d < std::numeric_limits<int>::min() || d > std::numeric_limits<int>::max() || std::isnan(d))
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(d) << std::endl;

    std::cout << "float: " << static_cast<float>(d) << "f" << std::endl;
    std::cout << "double: " << d << std::endl;
}
