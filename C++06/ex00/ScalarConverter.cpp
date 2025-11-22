#include "ScalarConverter.hpp"
#include "errno.h"
#include <cctype>
#include <cerrno>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <limits>

ScalarConverter::e_type ScalarConverter::detectType(const std::string &input) {
  if (input.empty() == true)
    return ERROR;
  if (input.length() == 1) {
    if (std::isdigit(input[0]) == true)
      return INT;
    if (std::isprint(input[0]))
      return CHAR;
    std::cerr << "Input of type char is not printable" << std::endl;
    return ERROR;
  }
  char *endl;
  errno = 0;
  if (strtol(input.c_str(), &endl, 10) && *endl == '\0' && errno != ERANGE)
    return INT;
  errno = 0;
  if (strtod(input.c_str(), &endl) && errno != ERANGE) {
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
  char c;
  int i;
  float f;
  double d;
  char *endl;
  std::ios::fmtflags old = std::cout.flags();

  if (type == ERROR)
    return;
  if (type == CHAR) {
    c = input[0];
    i = static_cast<int>(c);
    f = static_cast<float>(c);
    d = static_cast<double>(c);
    std::cout << "char: " << c << std::endl;
    std::cout << "int: " << i << std::endl;
    std::cout << "float: " << std::fixed << std::setprecision(1) << f << 'f'
              << std::endl;
    std::cout << "double: " << std::fixed << std::setprecision(1) << d
              << std::endl;
    std::cout.flags(old);
  }

  else if (type == INT) {
    long temp = strtol(input.c_str(), &endl, 10);
    if (temp <= std::numeric_limits<char>::max() &&
        temp >= std::numeric_limits<char>::min()) {
      if (std::isprint(static_cast<char>(temp))) {
        c = static_cast<char>(temp);
        std::cout << "char: " << c << std::endl;
      } else
        std::cout << "char: " << "Non displayable" << std::endl;
    } else
      std::cout << "char: " << "impossible" << std::endl;
    if (temp <= std::numeric_limits<int>::max() &&
        temp >= std::numeric_limits<int>::min())
      std::cout << "int: " << temp << std::endl;
    else
      std::cout << "int: " << "impossible" << std::endl;
    f = static_cast<float>(temp);
    d = static_cast<double>(temp);
    std::cout << "float: " << std::fixed << std::setprecision(1) << f << 'f'
              << std::endl;
    std::cout << "double: " << std::fixed << std::setprecision(1) << d
              << std::endl;
    std::cout.flags(old);
  } else if (type == FLOAT || type == DOUBLE) {
    double temp = strtod(input.c_str(), &endl);
    if (temp <= std::numeric_limits<char>::max() &&
        temp >= std::numeric_limits<char>::min()) {
      if (std::isprint(static_cast<char>(temp))) {
        c = static_cast<char>(temp);
        std::cout << "char: " << c << std::endl;
      } else
        std::cout << "char: " << "Non displayable" << std::endl;
    } else
      std::cout << "char: " << "impossible" << std::endl;
    if (temp <= std::numeric_limits<int>::max() &&
        temp >= std::numeric_limits<int>::min()) {
      i = static_cast<int>(temp);
      std::cout << "int: " << i << std::endl;
    } else
      std::cout << "int: " << "impossible" << std::endl;
    if (temp <= std::numeric_limits<float>::max() &&
        temp >= std::numeric_limits<float>::min()) {
      f = static_cast<float>(temp);
      std::cout << "float: " << std::fixed << std::setprecision(1) << f << 'f'
                << std::endl;
    } else
      std::cout << "float: " << "impossible" << std::endl;
    std::cout << "double: " << std::fixed << std::setprecision(1) << temp
              << std::endl;
    std::cout.flags(old);
  }
}
