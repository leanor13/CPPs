#include "BitcoinExchange.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <string>

bool isValidDate(const std::string& date) {
    if (date.length() != 10)
        return false;
    if (date[4] != '-' || date[7] != '-')
        return false;

    std::string yearStr = date.substr(0, 4);
    std::string monthStr = date.substr(5, 2);
    std::string dayStr = date.substr(8, 2);

    for (size_t i = 0; i < yearStr.size(); ++i)
        if (!isdigit(yearStr[i])) return false;
    for (size_t i = 0; i < monthStr.size(); ++i)
        if (!isdigit(monthStr[i])) return false;
    for (size_t i = 0; i < dayStr.size(); ++i)
        if (!isdigit(dayStr[i])) return false;

    //int year = atoi(yearStr.c_str());
    int month = atoi(monthStr.c_str());
    int day = atoi(dayStr.c_str());

    if (month < 1 || month > 12)
        return false;
    if (day < 1 || day > 31)
        return false;

    return true;
}


bool isValidValue(const std::string& valueStr, float& value) {
    std::istringstream ss(valueStr);
    ss >> value;
    if (ss.fail()) {
        std::cerr << "Error: bad input => " << valueStr << std::endl;
        return false;
    }
    if (value < 0) {
        std::cerr << "Error: not a positive number." << std::endl;
        return false;
    }
    if (value > 1000) {
        std::cerr << "Error: too large a number." << std::endl;
        return false;
    }
    return true;
}

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cerr << "Error. Usage: ./btc <input_file>" << std::endl;
        return 1;
    }

    BitcoinExchange btc;
    try {
        btc.loadRates("data.csv");
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }

    std::ifstream input(argv[1]);
    if (!input.is_open()) {
        std::cerr << "Error: could not open file. Check provided path" << std::endl;
        return 1;
    }

    std::string line;
    std::getline(input, line); // skip header

    while (std::getline(input, line)) {
        std::istringstream iss(line);
        std::string date, valueStr;

        if (!std::getline(iss, date, '|') || !std::getline(iss, valueStr)) {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }

        date.erase(date.find_last_not_of(" \t") + 1);
        valueStr.erase(0, valueStr.find_first_not_of(" \t"));

        float value;
        if (!isValidDate(date)) {
            std::cerr << "Error: bad input => " << date << std::endl;
            continue;
        }

        if (!isValidValue(valueStr, value))
            continue;

        try {
            float rate = btc.getRateForDate(date);
            std::cout << date << " => " << value << " = " << value * rate << std::endl;
        } catch (std::exception &e) {
            std::cerr << e.what() << std::endl;
        }
    }

    return 0;
}
