#include "PmergeMe.hpp"

int main(int argc, char **argv) {
    if (argc < 2) {
        std::cerr << "Error. Usage: ./PmergeMe <numbers>" << std::endl;
        return 1;
    }

    try {
        PmergeMe sorter;
        sorter.run(argc, argv);
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }

    return 0;
}

// ./PmergeMe `shuf -i 1-100000 -n 3000 | tr '\n' ' '`
// ./PmergeMe
// # Error

// ./PmergeMe -1 2
// # Error

// ./PmergeMe abc 2 3
// # Error


