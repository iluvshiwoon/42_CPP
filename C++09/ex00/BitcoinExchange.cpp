// #ifndef BITCOIN_EXCHANGE_HPP
// #define BITCOIN_EXCHANGE_HPP
// #include <map>
// #include <string>
// class BitcoinExchange {
// private:
//   std::map<std::string, double> _database; // do I need Compare ?
//   void _load_database(std::string filename);
//   bool _is_valid_database();
//
// public:
//   BitcoinExchange();
//   BitcoinExchange(const BitcoinExchange &other);
//   BitcoinExchange &operator=(const BitcoinExchange &rhs);
//   ~BitcoinExchange();
// };
// #endif
//
//

#include "BitcoinExchange.hpp"
#include <fstream>
#include <stdexcept>
#include <string>

std::string trim(std::string &str, std::string &set) {
  size_t begin = str.find_first_not_of(set);
  if (begin == std::string::npos)
    return std::string("");
  size_t end = str.find_last_not_of(set);
  return str.substr(begin, end - begin + 1);
}

void BitcoinExchange::_load_database(std::string filename) {
  std::ifstream istrm(filename);

  if (!istrm.is_open())
    throw std::runtime_error("open failed");

  std::string line;
  while (std::getline(istrm, line)) {
  }
}
