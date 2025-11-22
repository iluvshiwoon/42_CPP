#include "ScalarConverter.hpp"
#include <cstddef>
#include <iostream>
#include <limits>

int main(int argc, char **argv) {
  // if (argc != 2)
  //   std::cerr << "Usage: ./convert <arg>" << std::endl;
  // ScalarConverter::convert(argv[1]);

  // TEST
  (void)argc;
  (void)argv;
  std::string test[] = {
      "-inf",
      "inf",
      "nan",
      "-inff",
      "+inff",
      "nanf",
      "a",
      "^",
      "0",
      "0.0",
      "-50.0",
      "255",
      "42f",
      "42.0f",
      "42.0",
      "-2147483648",
      "2147483647",
      "-9223372036854775808",
      "9223372036854775807",
      "1e-38",
      "-1e-38",
      "3e+38",
      "4e+38",
      "-3e+38",
      "2e+308",
      "-2e+308",
      "2e-308",
      "-2e-308",
      "3e308",
  };
  std::size_t end = sizeof(test) / sizeof(test[0]);
  for (std::size_t i = 0; i < end; i++) {
    std::cout << "./convert " << test[i] << std::endl;
    ScalarConverter::convert(test[i]);
    if (i + 1 < end)
      std::cout << "---------------------------------------------------"
                << std::endl;
  };
  std::cout << std::numeric_limits<char>::max() << std::endl;
  std::cout << std::numeric_limits<int>::max() << std::endl;
  std::cout << std::numeric_limits<long>::max() << std::endl;
  std::cout << std::numeric_limits<float>::max() << std::endl;
  std::cout << std::numeric_limits<double>::max() << std::endl;
  std::cout << std::numeric_limits<char>::min() << std::endl;
  std::cout << std::numeric_limits<int>::min() << std::endl;
  std::cout << std::numeric_limits<long>::min() << std::endl;
  std::cout << std::numeric_limits<float>::min() << std::endl;
  std::cout << std::numeric_limits<double>::min() << std::endl;
  return 0;
}
