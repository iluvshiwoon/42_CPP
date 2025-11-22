#include "ScalarConverter.hpp"
#include "errno.h"
#include <cctype>
#include <cerrno>
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <limits>

ScalarConverter::e_type ScalarConverter::detectType(const std::string &input) {
  if (input.empty() == true)
    return ERROR;
  if (input.length() == 1 && std::isdigit(input[0]) == false) {
    if (std::isprint(input[0]))
      return CHAR;
    std::cerr << "Input of type char is not printable" << std::endl;
    return ERROR;
  }
  char *endl;
  strtod(input.c_str(), &endl);
  if (*endl == '\0' || (*endl == 'f' && *(endl + 1) == '\0'))
    return DOUBLE;
  std::cerr << "Input is not of any supported types" << std::endl;
  return ERROR;
};

void ScalarConverter::convert(const std::string &input) {
  const ScalarConverter::e_type type = ScalarConverter::detectType(input);
  double val;
  char *endl;

  if (type == ERROR)
    return;
  if (type == CHAR)
    val = static_cast<double>(input[0]);
  else
    val = strtod(input.c_str(), &endl);
  std::cout << "char: ";
  if (std::isinf(val) || std::isnan(val) ||
      val < std::numeric_limits<char>::min() ||
      val > std::numeric_limits<char>::max())
    std::cout << "impossible" << std::endl;
  else if (std::isprint(val))
    std::cout << "'" << static_cast<char>(val) << "'" << std::endl;
  else
    std::cout << "Non displayable" << std::endl;
  std::cout << "int: ";
  if (std::isinf(val) || std::isnan(val) ||
      val < std::numeric_limits<int>::min() ||
      val > std::numeric_limits<int>::max())
    std::cout << "impossible" << std::endl;
  else
    std::cout << static_cast<int>(val) << std::endl;
  std::cout << "float: ";
  if (std::isnan(val) == false && std::isinf(val) == false &&
      std::abs(val) > std::numeric_limits<float>::max())
    std::cout << "impossible" << std::endl;
  else
    std::cout << std::fixed << std::setprecision(1) << val << "f" << std::endl;
  std::cout << "double: " << val << std::endl;
}
