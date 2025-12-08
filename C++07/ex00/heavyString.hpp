#ifndef HEAVY_STRING_HPP
#define HEAVY_STRING_HPP
#include <cstring>
#include <iostream>
class heavyString {
private:
  char *buffer;

public:
  heavyString() : buffer(NULL) {}

  heavyString(const char *str) {
    if (str) {
      buffer = new char[strlen(str) + 1];
      strcpy(buffer, str);
    } else {
      buffer = NULL;
    }
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
#endif
