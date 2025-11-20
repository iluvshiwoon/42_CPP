#include "ScalarConverter.hpp"
#include <cctype>
#include <cstdlib>
#include <iostream>
#include <mutex>

ScalarConverter::ScalarConverter() {};
ScalarConverter::ScalarConverter(const ScalarConverter &other) {};
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &rhs) {
  return *this;
};

ScalarConverter::~ScalarConverter() {};

const ScalarConverter::e_type
ScalarConverter::detectType(const std::string &input) {
  if (input.empty() == true)
    return ERROR;
  if (input.length() == 1 && std::isdigit(input[0]) == false) {
    if (std::isprint(input[0]))
      return CHAR;
    std::cerr << "Input of type char is not printable" << std::endl;
    return ERROR;
  }
  char *endl;
  if (strtol(input.c_str(), &endl, 10) && *endl == '\0')
    return INT;
  if (strtod(input.c_str(), &endl)) {
    if (*endl == '\0')
      return DOUBLE;
    if (*endl == 'f' && *(endl + 1) == '\0')
      return FLOAT;
  }
  std::cerr << "Input is not of any supported types" << std::endl;
  return ERROR;
};

void ScalarConverter::convert(const std::string &input) {
  const ScalarConverter::e_type type = ScalarConverter::detectType(input);
  if (type == ERROR)
    return;
  if (type == CHAR) {
  }
}
