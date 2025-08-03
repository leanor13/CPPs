#include "BitcoinExchange.hpp"
#include <fstream>
#include <sstream>
#include <iostream>
#include <cstdlib>

BitcoinExchange::BitcoinExchange() {}
BitcoinExchange::~BitcoinExchange() {}

void BitcoinExchange::loadRates(const std::string& filename) {
    std::ifstream file(filename.c_str());
    if (!file)
        throw std::runtime_error("Error: could not open database.");

    std::string line;
    std::getline(file, line); // skip header

    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string date, valueStr;
        if (!std::getline(iss, date, ',') || !std::getline(iss, valueStr))
            continue;

        float value = std::strtof(valueStr.c_str(), NULL);
        _exchangeRates[date] = value;
    }
}

float BitcoinExchange::getRateForDate(const std::string& date) const {
    std::map<std::string, float>::const_iterator it = _exchangeRates.lower_bound(date);

    if (it != _exchangeRates.end() && it->first == date)
        return it->second;
    if (it == _exchangeRates.begin())
        throw std::runtime_error("Error: no earlier date found.");
    --it;
    return it->second;
}
