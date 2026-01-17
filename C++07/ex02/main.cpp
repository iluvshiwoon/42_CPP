#include "Array.hpp"
#include <iostream>
#include <stdlib.h>
#define MAX_VAL 750

int main() {
  Array<int> a;
  std::cout << "a's size: " << a.size() << std::endl;
  try {
    a[5];
  } catch (std::exception &e) {
    std::cout << "Tried a[5]: ";
    std::cout << e.what() << std::endl;
  }

  Array<char> c(3);
  c[0] = 'a';
  c[1] = 'b';
  c[2] = 'c';
  std::cout << "c[2]: " << c[2] << std::endl;

  Array<char> c_cpy(c);
  c[2] = 'a';
  std::cout << "c_cpy[2]: " << c_cpy[2] << std::endl;
  Array<int> numbers(MAX_VAL);
  int *mirror = new int[MAX_VAL];
  srand(time(NULL));
  for (int i = 0; i < MAX_VAL; i++) {
    const int value = rand();
    numbers[i] = value;
    mirror[i] = value;
  }
  // SCOPE
  {
    Array<int> tmp = numbers;
    Array<int> test(tmp);
  }

  for (int i = 0; i < MAX_VAL; i++) {
    if (mirror[i] != numbers[i]) {
      std::cerr << "didn't save the same value!!" << std::endl;
      return 1;
    }
  }
  try {
    numbers[-2] = 0;
  } catch (const std::exception &e) {
    std::cerr << e.what() << '\n';
  }
  try {
    numbers[MAX_VAL] = 0;
  } catch (const std::exception &e) {
    std::cerr << e.what() << '\n';
  }

  for (int i = 0; i < MAX_VAL; i++) {
    numbers[i] = rand();
  }
  delete[] mirror; //
  return 0;
}
