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
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>

// std::string trim(std::string &str, std::string &set) {
//   size_t begin = str.find_first_not_of(set);
//   if (begin == std::string::npos)
//     return std::string("");
//   size_t end = str.find_last_not_of(set);
//   return str.substr(begin, end - begin + 1);
// }

BitcoinExchange::BitcoinExchange() { _load_database("data.csv"); }

BitcoinExchange::~BitcoinExchange() {};

bool BitcoinExchange::_check_date(int n, const std::string &date) {

  // 2011
  // 7
  // 31
  // line 315: Invalid date
  std::istringstream ss(date);
  int year;
  int month;
  int day;

  ss >> year;
  ss >> month;
  ss >> day;

  month *= -1;
  day *= -1;

  int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  if (year > 0 && (month >= 1 && month <= 12)) {
    if (day <= days[month - 1] && day >= 1)
      return true;
    else if (month == 2 && day == 29) {
      if (year % 4 == 0 || (year % 100 == 0 && year % 400 == 0))
        return true;
    }
  }

  std::cout << year << std::endl;
  std::cout << month << std::endl;
  std::cout << day << std::endl;

  std::cerr << "line " << n << ": Invalid date\n";
  return false;
}

float BitcoinExchange::_check_value(int n, const std::string &value_s) {
  std::istringstream ss(value_s);
  float value_f;

  ss >> value_f;

  if (value_f >= 0)
    return value_f;

  std::cerr << "line " << n << ": Invalid price\n";
  return -1;
}

void BitcoinExchange::_load_database(const std::string &filename) {
  std::ifstream istrm(filename.c_str());

  if (!istrm.is_open()) {
    std::cerr << filename;
    throw std::runtime_error(" failed to open\n");
  }

  std::string line;
  std::string date;
  std::string value_s;
  std::string::size_type i;
  float value_f;
  int n = 0;
  while (std::getline(istrm, line)) {
    if (n++ == 0)
      continue;

    i = line.find(',');
    if (i == std::string::npos) {
      std::cerr << "line " << n << ": wrong format\n";
      continue;
    }
    date = line.substr(0, i);
    value_s = line.substr(i + 1);
    if (_check_date(n, date) && (value_f = _check_value(n, value_s)))
      _database[date] = value_f;
  }
  if (n <= 1)
    throw std::runtime_error("Invalid csv");
}
