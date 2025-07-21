#include "easyfind.hpp"
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
  return 0;
}