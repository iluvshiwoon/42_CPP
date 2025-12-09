#include "iter.hpp"
#include <iostream>

template <typename T> void print(T &type) { std::cout << type << std::endl; }

int main() {
  int a[] = {1, 2, 3};
  iter(a, 3, print<int>);
  const int *c_a = a;
  iter(c_a, 3, print<const int>);
  return 0;
}
