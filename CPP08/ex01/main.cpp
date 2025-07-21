#include "Span.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>

int main() {
  // Пример из задания
  Span sp = Span(5);
  sp.addNumber(6);
  sp.addNumber(3);
  sp.addNumber(17);
  sp.addNumber(9);
  sp.addNumber(11);
  std::cout << sp.shortestSpan() << std::endl;
  std::cout << sp.longestSpan() << std::endl;

  // Проверка исключения при переполнении
  try {
    sp.addNumber(42);
  } catch (const std::exception &e) {
    std::cout << "Exception: " << e.what() << std::endl;
  }

  // Проверка исключения при недостатке чисел
  try {
    Span sp2(1);
    sp2.addNumber(1);
    std::cout << sp2.shortestSpan() << std::endl;
  } catch (const std::exception &e) {
    std::cout << "Exception: " << e.what() << std::endl;
  }

  // Тест с большим количеством чисел и addRange
  Span big(10000);
  std::vector<int> v;
  for (int i = 0; i < 10000; ++i)
    v.push_back(i * 2);
  big.addRange(v.begin(), v.end());
  std::cout << "Big shortest: " << big.shortestSpan() << std::endl;
  std::cout << "Big longest: " << big.longestSpan() << std::endl;

  return 0;
}