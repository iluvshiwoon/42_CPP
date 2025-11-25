#include "Data.h"
#include "Serialize.hpp"
#include <iostream>

int main() {
  Data a = {1.1, 2.2};
  std::cout << "Before serialization:\nx: " << a.x << "\ny: " << a.y
            << std::endl;
  Data *b = Serialize::deserialize(Serialize::serialize(&a));

  std::cout << '\n';
  if (b == &a)
    std::cout << b << " is equal to: " << &a << std::endl;
  std::cout << '\n';

  std::cout << "After serialization:\nx: " << b->x << "\ny: " << b->y
            << std::endl;
  return 0;
}
