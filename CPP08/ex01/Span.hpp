#ifndef SPAN_HPP
#define SPAN_HPP

#include <exception>
#include <vector>

class Span {
public:
  Span(unsigned int n);
  Span(const Span &other);
  Span &operator=(const Span &other);
  ~Span();

  void addNumber(int number);
  template <typename InputIt> void addRange(InputIt first, InputIt last) {
    if (_numbers.size() + std::distance(first, last) > _maxSize)
      throw FullSpanException();
    _numbers.insert(_numbers.end(), first, last);
  }
  int shortestSpan() const;
  int longestSpan() const;

  class FullSpanException : public std::exception {
  public:
    const char *what() const throw() { return "Span is full"; }
  };
  class NoSpanException : public std::exception {
  public:
    const char *what() const throw() {
      return "Not enough numbers to find a span";
    }
  };

private:
  unsigned int _maxSize;
  std::vector<int> _numbers;
};

#endif // SPAN_HPP