#include "easyfind.hpp"
#include <deque>
#include <iostream>
#include <list>
#include <vector>

int main() {
  std::vector<int> v;
  for (int i = 0; i < 10; ++i)
    v.push_back(i * 2);
  try {
    std::cout << "Found: " << easyfind(v, 6) << std::endl;
    std::cout << "Found: " << easyfind(v, 15) << std::endl; // not found
  } catch (const std::exception &e) {
    std::cout << e.what() << std::endl;
  }

  std::list<int> l;
  for (int i = 0; i < 5; ++i)
    l.push_back(i + 1);
  try {
    std::cout << "Found: " << easyfind(l, 3) << std::endl;
    std::cout << "Found: " << easyfind(l, 42) << std::endl; // not found
  } catch (const std::exception &e) {
    std::cout << e.what() << std::endl;
  }

  // Corner case: поиск в пустом контейнере
  std::vector<int> empty;
  try {
    std::cout << "Found: " << easyfind(empty, 1) << std::endl;
  } catch (const std::exception &e) {
    std::cout << "Empty vector: " << e.what() << std::endl;
  }

  // Corner case: std::deque
  std::deque<int> d;
  d.push_back(10);
  d.push_back(20);
  try {
    std::cout << "Found: " << easyfind(d, 20) << std::endl;
    std::cout << "Found: " << easyfind(d, 99) << std::endl;
  } catch (const std::exception &e) {
    std::cout << e.what() << std::endl;
  }
  return 0;
}