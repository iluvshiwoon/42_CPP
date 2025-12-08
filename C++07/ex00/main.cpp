#include "heavyString.hpp"
#include "swap.hpp"

int main() {
  heavyString s1("Hello");
  heavyString s2("World");
  int i1(5);
  int i2(10);

  std::cout << "Before:" << std::endl;
  s1.print();
  s2.print();

  swap(s1, s2);

  std::cout << "After:" << std::endl;
  s1.print();
  s2.print();

  std::cout << "Before:" << std::endl;
  std::cout << "i1: " << i1 << " | i2: " << i2 << std::endl;

  swap(i1, i2);

  std::cout << "After:" << std::endl;
  std::cout << "i1: " << i1 << " | i2: " << i2 << std::endl;

  return 0;
}
