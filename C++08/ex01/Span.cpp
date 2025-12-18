#include "Span.hpp"
#include <algorithm>
#include <exception>
#include <limits>

Span::Span(unsigned int maxNum) : _maxNum(maxNum) {}
Span::Span(const Span &other)
    : _maxNum(other._maxNum), _numbers(other._numbers) {}
Span::~Span() {}
void Span::addNumber(int value) {
  if (this->_numbers.size() >= this->_maxNum)
    throw std::exception();
  this->_numbers.push_back(value);
}

unsigned int Span::longestSpan() const {
  if (this->_numbers.size() < 2)
    throw std::exception();
  int max = *std::max_element(this->_numbers.begin(), this->_numbers.end());
  int min = *std::min_element(this->_numbers.begin(), this->_numbers.end());
  return max - min;
}

unsigned int Span::shortestSpan() const {
  if (this->_numbers.size() < 2)
    throw std::exception();
  std::vector<int> sorted = this->_numbers;
  std::sort(sorted.begin(), sorted.end());
  int min_span = std::numeric_limits<int>::max();
  int span;
  for (size_t i = 0; i < sorted.size() - 1; i++) {
    span = sorted[i + 1] - sorted[i];
    if (span < min_span) {
      min_span = span;
    }
  }
  return min_span;
}
