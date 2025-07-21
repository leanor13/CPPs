#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <exception>

class NotFoundException : public std::exception {
public:
  const char *what() const throw() { return "Value not found"; }
};

template <typename T> int easyfind(const T &container, int value) {
  typename T::const_iterator it =
      std::find(container.begin(), container.end(), value);
  if (it == container.end())
    throw NotFoundException();
  return *it;
}

#endif // EASYFIND_HPP