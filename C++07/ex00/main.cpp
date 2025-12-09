#include "heavyString.hpp"
#include "max.hpp"
#include "min.hpp"
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

  std::cout << "\n\n----------Subject-MAIN----------\n\n";
  int a = 2;
  int b = 3;
  ::swap(a, b);
  std::cout << "a = " << a << ", b = " << b << std::endl;
  std::cout << "min( a, b ) = " << ::min(a, b) << std::endl;
  std::cout << "max( a, b ) = " << ::max(a, b) << std::endl;
  std::string c = "chaine1";
  std::string d = "chaine2";
  ::swap(c, d);
  std::cout << "c = " << c << ", d = " << d << std::endl;
  std::cout << "min( c, d ) = " << ::min(c, d) << std::endl;
  std::cout << "max( c, d ) = " << ::max(c, d) << std::endl;

  return 0;
}
