#ifndef RPN_HPP
#define RPN_HPP

#include <string>
#include <deque>

class RPN {
private:
    std::deque<int> _stack;

public:
    RPN();
    ~RPN();

    int evaluate(const std::string& expression);
};

#endif
