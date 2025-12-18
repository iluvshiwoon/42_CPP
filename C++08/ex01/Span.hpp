#include <exception>
#include <iterator>
#include <vector>
class Span {
private:
  unsigned int _maxNum;
  std::vector<int> _numbers;

public:
  Span(unsigned int maxNum);
  Span(const Span &other);
  Span &operator=(const Span &rhs);
  ~Span();
  void addNumber(int value);
  unsigned int longestSpan() const;
  unsigned int shortestSpan() const;

  template <typename Iterator> void addNumber(Iterator begin, Iterator end);
};

template <typename Iterator>
void Span::addNumber(Iterator begin, Iterator end) {
  unsigned int size = std::distance(begin, end);
  if (this->_numbers.size() + size > this->_maxNum)
    throw std::exception();
  this->_numbers.insert(this->_numbers.end(), begin, end);
}
