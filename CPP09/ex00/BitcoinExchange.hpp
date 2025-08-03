#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <string>

class BitcoinExchange {
private:
    std::map<std::string, float> _exchangeRates;

public:
    BitcoinExchange();
    ~BitcoinExchange();

    void loadRates(const std::string& filename);
    float getRateForDate(const std::string& date) const;
};

#endif
