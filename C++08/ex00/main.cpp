#include "easyfind.hpp"
#include <exception>
#include <iostream>
#include <list>
#include <vector>
int main() {
  std::vector<int> a;
  a.push_back(10);
  a.push_back(11);
  a.push_back(12);
  const std::vector<int> const_a(a);
  std::cout << "Test: const std::vector<int>" << std::endl;
  try {
    std::vector<int>::const_iterator it = easyfind(const_a, 11);
    std::cout << "Expect: 11 Got: " << *it << std::endl;
  } catch (std::exception &e) {
    std::cout << "Error: " << e.what() << std::endl;
  }
  std::cout << "Test: std::vector<int>" << std::endl;
  try {
    std::vector<int>::iterator it = easyfind(a, 11);
    std::cout << "Expect: 11 Got: " << *it << std::endl;
  } catch (std::exception &e) {
    std::cout << "Error: " << e.what() << std::endl;
  }
  std::cout << "Test: std::list<int>" << std::endl;
  std::list<int> b;
  b.push_back(10);
  b.push_back(11);
  b.push_back(12);
  try {
    std::list<int>::iterator it = easyfind(b, 11);
    std::cout << "Expect: 11 Got: " << *it << std::endl;
  } catch (std::exception &e) {
    std::cout << "Error: " << e.what() << std::endl;
  }
  std::cout << "Should give error:" << std::endl;
  try {
    std::list<int>::iterator it = easyfind(b, 110);
    std::cout << "Expect: error" << *it << std::endl;
  } catch (std::exception &e) {
    std::cout << "Error: " << e.what() << std::endl;
  }
  try {
    std::vector<int>::iterator it = easyfind(a, 110);
    std::cout << "Expect: error" << *it << std::endl;
  } catch (std::exception &e) {
    std::cout << "Error: " << e.what() << std::endl;
  }
  return 0;
}
