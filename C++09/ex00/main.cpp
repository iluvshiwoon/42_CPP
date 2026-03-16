#include "BitcoinExchange.hpp"
std::string trim(std::string str, std::string set) {
  size_t begin = str.find_first_not_of(set);
  size_t end = str.find_last_not_of(set);
  if (begin == std::string::npos)
    return std::string("");
  return str.substr(begin, end - begin + 1);
}

#include <iostream>
int main() { std::cout << trim("  4535353 |  | ", " ") << std::endl; }
