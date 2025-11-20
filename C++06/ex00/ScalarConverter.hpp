#ifndef SCALAR_CONVERTER_HPP
#define SCALAR_CONVERTER_HPP
#include <string>
class ScalarConverter {
private:
  ScalarConverter();
  ScalarConverter(const ScalarConverter &other);
  ScalarConverter &operator=(const ScalarConverter &rhs);
  ~ScalarConverter();
  enum e_type { CHAR, INT, FLOAT, DOUBLE, ERROR };
  static const e_type detectType(const std::string &input);

public:
  static void convert(const std::string &input);
};
#endif
