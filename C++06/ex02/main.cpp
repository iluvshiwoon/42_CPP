#include "A.hpp"
#include "B.hpp"
#include "Base.hpp"
#include "C.hpp"
#include <cstdlib>
#include <ctime>
#include <exception>
#include <iostream>

Base *generate(void) {
  int i = std::rand() % 3;
  switch (i) {
  case 0:
    return new A();
  case 1:
    return new B();
  case 2:
    return new C();
  }
  return NULL;
}

void identify(Base *p) {
  if (dynamic_cast<A *>(p) != NULL)
    std::cout << "A";
  else if (dynamic_cast<B *>(p) != NULL)
    std::cout << "B";
  else if (dynamic_cast<C *>(p) != NULL)
    std::cout << "C";
  else
    std::cout << "Unknown";
  std::cout << std::endl;
}

void identify(Base &p) {
  try {
    (void)dynamic_cast<A &>(p);
    std::cout << "A" << std::endl;
  } catch (const std::exception &e) {
    try {
      (void)dynamic_cast<B &>(p);
      std::cout << "B" << std::endl;
    } catch (const std::exception &e) {
      try {
        (void)dynamic_cast<C &>(p);
        std::cout << "C" << std::endl;
      } catch (const std::exception &e) {
        std::cout << "Unknown" << std::endl;
        throw;
      }
    }
  }
}

int main() {
  std::srand(static_cast<unsigned int>(std::time(NULL)));
  Base *one = generate();
  Base *two = generate();
  Base *three = generate();
  Base *none = new Base();
  identify(one);
  identify(two);
  identify(three);
  identify(none);
  std::cout << "--------------" << std::endl;
  try {
    identify(*one);
  } catch (const std::exception &e) {
  }
  try {
    identify(*two);
  } catch (const std::exception &e) {
  }
  try {
    identify(*three);
  } catch (const std::exception &e) {
  }
  try {
    identify(*none);
  } catch (const std::exception &e) {
  }
  delete one;
  delete two;
  delete three;
  delete none;
  return 0;
}
