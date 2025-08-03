#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <list>
#include <string>
#include <cstdlib>
#include <stdexcept>
#include <iostream>
#include <ctime>

class PmergeMe {
public:
    PmergeMe();
    ~PmergeMe();

    void run(int argc, char **argv);

private:
    void parseArgs(int argc, char **argv, std::vector<int>& vec);
    void printContainer(const std::string& label, const std::vector<int>& cont);

    void sortVector(std::vector<int>& data);
    void sortList(std::list<int>& data);
};

#endif
