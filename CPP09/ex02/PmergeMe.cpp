#include "PmergeMe.hpp"
#include <climits>
#include <algorithm>

// Constructor/Destructor
PmergeMe::PmergeMe() {}
PmergeMe::~PmergeMe() {}

void PmergeMe::run(int argc, char **argv) {
    std::vector<int> vec;
    parseArgs(argc, argv, vec);

    std::list<int> lst(vec.begin(), vec.end());

    printContainer("Before:", vec);

    clock_t startVec = clock();
    sortVector(vec);
    clock_t endVec = clock();

    clock_t startList = clock();
    sortList(lst);
    clock_t endList = clock();

    printContainer("After:", vec);

    std::cout << "Time to process a range of " << vec.size()
              << " elements with std::vector : "
              << static_cast<double>(endVec - startVec) / CLOCKS_PER_SEC * 1e6 << " us" << std::endl;

    std::cout << "Time to process a range of " << lst.size()
              << " elements with std::list : "
              << static_cast<double>(endList - startList) / CLOCKS_PER_SEC * 1e6 << " us" << std::endl;
}

void PmergeMe::parseArgs(int argc, char **argv, std::vector<int>& vec) {
    for (int i = 1; i < argc; ++i) {
        std::string arg(argv[i]);
        for (size_t j = 0; j < arg.size(); ++j)
            if (!isdigit(arg[j]))
                throw std::runtime_error("Error. Only positive integers are allowed.");

        long val = std::strtol(arg.c_str(), NULL, 10);
        if (val < 0 || val > INT_MAX)
            throw std::runtime_error("Error. Only positive integers are allowed.");

        vec.push_back(static_cast<int>(val));
    }
}

void PmergeMe::printContainer(const std::string& label, const std::vector<int>& cont) {
    std::cout << label;
    for (size_t i = 0; i < cont.size(); ++i)
        std::cout << " " << cont[i];
    std::cout << std::endl;
}

static void mergeInsertSortVector(std::vector<int>& input) {
    if (input.size() <= 1)
        return;

    std::vector<int> mainChain;
    std::vector<int> pending;

    // 1. Pairing and splitting
    for (size_t i = 0; i + 1 < input.size(); i += 2) {
        int first = input[i];
        int second = input[i + 1];
        if (first > second)
            std::swap(first, second);
        pending.push_back(first);     // smaller
        mainChain.push_back(second);  // larger
    }

    // If odd number of elements, push last element to mainChain
    if (input.size() % 2 != 0)
        mainChain.push_back(input.back());

    // 2. Sort main chain
    std::sort(mainChain.begin(), mainChain.end());

    // 3. Insert pending one by one
    for (size_t i = 0; i < pending.size(); ++i) {
        std::vector<int>::iterator pos = std::lower_bound(mainChain.begin(), mainChain.end(), pending[i]);
        mainChain.insert(pos, pending[i]);
    }

    input = mainChain;
}

static void mergeInsertSortList(std::list<int>& input) {
    if (input.size() <= 1)
        return;

    std::list<int> mainChain;
    std::list<int> pending;

    std::list<int>::iterator it = input.begin();
    while (it != input.end()) {
        int first = *it;
        ++it;
        if (it == input.end()) {
            mainChain.push_back(first);
            break;
        }
        int second = *it;
        ++it;

        if (first > second)
            std::swap(first, second);
        pending.push_back(first);
        mainChain.push_back(second);
    }

    mainChain.sort();

    for (std::list<int>::iterator pit = pending.begin(); pit != pending.end(); ++pit) {
        std::list<int>::iterator insertPos = std::lower_bound(mainChain.begin(), mainChain.end(), *pit);
        mainChain.insert(insertPos, *pit);
    }

    input = mainChain;
}


void PmergeMe::sortVector(std::vector<int>& data) {
    mergeInsertSortVector(data);
}

void PmergeMe::sortList(std::list<int>& data) {
    mergeInsertSortList(data);
}

