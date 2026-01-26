#include "Span.hpp"
#include <cstddef>
#include <cstdlib>
#include <exception>
#include <iostream>
int main() {
  std::cout << "SUBJECT MAIN\n" << std::endl;
  Span sp(5);
  sp.addNumber(6);
  sp.addNumber(3);
  sp.addNumber(17);
  sp.addNumber(9);
  sp.addNumber(11);
  std::cout << sp.shortestSpan() << std::endl;
  std::cout << sp.longestSpan() << std::endl;

  std::cout << "COMPARE RESULT\n" << std::endl;
  size_t N = 1000000;
  std::srand(time(NULL));
  std::vector<int> raw;
  for (size_t i = 0; i < N; i++)
    raw.push_back(std::rand());
  Span a(N);
  for (size_t i = 0; i < N; i++)
    a.addNumber(raw[i]);
  Span b(N);
  b.addNumber(raw.begin(), raw.end());
  if (a.shortestSpan() == b.shortestSpan())
    std::cout << "Pass" << std::endl;
  if (a.longestSpan() == b.longestSpan())
    std::cout << "Pass" << std::endl;
  std::cout << "TEST EXCEPTION\n" << std::endl;
  try {
    a.addNumber(4);
    std::cout << "Failed" << std::endl;
  } catch (std::exception &e) {
    std::cout << "Pass" << std::endl;
  }
  try {
    b.addNumber(raw.begin(), raw.end());
    std::cout << "Failed" << std::endl;
  } catch (std::exception &e) {
    std::cout << "Pass" << std::endl;
  }
  return 0;
}
