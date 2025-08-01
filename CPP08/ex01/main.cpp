#include "Span.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>

int main() {
  // From the subject
  Span sp = Span(5);
  sp.addNumber(6);
  sp.addNumber(3);
  sp.addNumber(17);
  sp.addNumber(9);
  sp.addNumber(11);
  std::cout << sp.shortestSpan() << std::endl;
  std::cout << sp.longestSpan() << std::endl;

  // checking overflow
  try {
    sp.addNumber(42);
  } catch (const std::exception &e) {
    std::cout << "Exception: " << e.what() << std::endl;
  }

  // checking not enough numbers for span
  try {
    Span sp2(1);
    sp2.addNumber(1);
    std::cout << sp2.shortestSpan() << std::endl;
  } catch (const std::exception &e) {
    std::cout << "Exception: " << e.what() << std::endl;
  }

  // Testing with a large number of elements and addRange
  Span big(10000);
  std::vector<int> v;
  for (int i = 0; i < 10000; ++i)
    v.push_back(i * 2);
  big.addRange(v.begin(), v.end());
  std::cout << "Big shortest: " << big.shortestSpan() << std::endl;
  std::cout << "Big longest: " << big.longestSpan() << std::endl;

  // Corner case: addRange exceeds size
  try {
    Span sp3(3);
    std::vector<int> v2;
    v2.push_back(1);
    v2.push_back(2);
    v2.push_back(3);
    v2.push_back(4);
    sp3.addRange(v2.begin(), v2.end());
  } catch (const std::exception &e) {
    std::cout << "Exception: " << e.what() << std::endl;
  }

  // Corner case: negative numbers
  Span sp4(3);
  sp4.addNumber(-10);
  sp4.addNumber(0);
  sp4.addNumber(10);
  std::cout << "Negative shortest: " << sp4.shortestSpan() << std::endl;
  std::cout << "Negative longest: " << sp4.longestSpan() << std::endl;

  // Corner case: same numbers
  Span sp5(3);
  sp5.addNumber(7);
  sp5.addNumber(7);
  sp5.addNumber(7);
  std::cout << "Same shortest: " << sp5.shortestSpan() << std::endl;
  std::cout << "Same longest: " << sp5.longestSpan() << std::endl;

  return 0;
}