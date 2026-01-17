#include "Array.hpp"
#include <exception>
#include <iostream>
#include <stdlib.h>
#define MAX_VAL 750
#include <cstring>
#include <iostream>

class heavyString {
private:
  char *buffer;

public:
  heavyString() : buffer(NULL) {}

  explicit heavyString(const char *str) {
    if (str) {
      buffer = new char[strlen(str) + 1];
      strcpy(buffer, str);
    } else {
      buffer = NULL;
    }
    std::cout << "[LOG] Constructor: Value \"" << (buffer ? buffer : "null")
              << "\"" << std::endl;
  }

  heavyString(const heavyString &other) {
    if (other.buffer) {
      buffer = new char[strlen(other.buffer) + 1];
      strcpy(buffer, other.buffer);
    } else {
      buffer = NULL;
    }
    std::cout << "[LOG] Copy Constructor: Copied \""
              << (buffer ? buffer : "null") << "\"" << std::endl;
  }

  heavyString &operator=(const heavyString &other) {
    std::cout << "[LOG] Assignment Op: Overwriting \""
              << (buffer ? buffer : "null") << "\" with \""
              << (other.buffer ? other.buffer : "null") << "\"" << std::endl;

    if (this == &other)
      return *this;

    delete[] buffer;

    if (other.buffer) {
      buffer = new char[strlen(other.buffer) + 1];
      strcpy(buffer, other.buffer);
    } else {
      buffer = NULL;
    }
    return *this;
  }

  ~heavyString() {
    if (buffer) {

      delete[] buffer;
    }
  }

  void print() const {
    std::cout << "Value: " << (buffer ? buffer : "null") << std::endl;
  }
};

int main() {
  Array<heavyString> a;
  std::cout << "Size: " << a.size() << " and Data: ";
  try {
    a[0].print();
  } catch (std::exception &e) {
    std::cout << e.what() << " Cause _data is NULL" << std::endl;
  }
  Array<heavyString> b(45);
  std::cout << "Size: " << b.size() << " and Data: ";
  try {
    std::cout << "b[0]: ";
    b[0].print();
  } catch (std::exception &e) {
    std::cout << "this shouldn't fail" << std::endl;
  }
  Array<heavyString> deep1(2);
  deep1[0] = heavyString("test");
  deep1[0].print();
}
