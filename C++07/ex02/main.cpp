#include "Array.hpp"
#include <cstring>
#include <exception>
#include <iostream>
#include <stdlib.h>

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
  deep1[1] = heavyString("test1");
  Array<heavyString> deep2(deep1);
  deep2[1] = heavyString("...");
  std::cout << "deep1[1] is: ";
  deep1[1].print();
  std::cout << "deep2[1] is: ";
  deep2[1].print();
  std::cout << std::endl;
  try {
    deep1[1] = heavyString("changed test1");
    deep1[1].print();
  } catch (std::exception &e) {
    std::cout << "this shouldn't fail" << std::endl;
  }
  try {
    const Array<heavyString> const_deep(1);
    heavyString test = const_deep[0];
    test = heavyString("test");
    // const_deep[0] = heavyString("test");
  } catch (std::exception &e) {
    std::cout << "this shouldn't fail" << std::endl;
  }
}
