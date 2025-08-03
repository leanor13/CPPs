#include "RPN.hpp"
#include <sstream>
#include <iostream>
#include <cstdlib>

RPN::RPN() {}
RPN::~RPN() {}

int RPN::evaluate(const std::string& expression) {
    std::istringstream iss(expression);
    std::string token;

    while (iss >> token) {
        if (token.length() == 1 && isdigit(token[0])) {
            _stack.push_back(token[0] - '0');
        } else if (token == "+" || token == "-" || token == "*" || token == "/") {
            if (_stack.size() < 2) {
                throw std::runtime_error("Error: not enough operands.");
            }
            int b = _stack.back(); _stack.pop_back();
            int a = _stack.back(); _stack.pop_back();
            int result = 0;

            if (token == "+") result = a + b;
            else if (token == "-") result = a - b;
            else if (token == "*") result = a * b;
            else if (token == "/") {
                if (b == 0)
                    throw std::runtime_error("Error: division by zero.");
                result = a / b;
            }
            _stack.push_back(result);
        } else {
            throw std::runtime_error("Error: invalid token.");
        }
    }

    if (_stack.size() != 1) {
        throw std::runtime_error("Error: too many operands.");
    }

    return _stack.back();
}
