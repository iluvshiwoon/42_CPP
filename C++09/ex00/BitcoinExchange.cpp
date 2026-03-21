#include "BitcoinExchange.hpp"
#include <fstream>
#include <ios>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>

BitcoinExchange::BitcoinExchange() { _load_database("data.csv"); }

BitcoinExchange::~BitcoinExchange() {};

bool BitcoinExchange::_check_date(int n, const std::string &date) {
  int year = -1;
  int month = -1;
  int day = -1;
  char dash1;
  char dash2;
  char trailing;

  std::istringstream ss(date);

  if (ss >> std::noskipws >> year && ss >> dash1 && ss >> month &&
      ss >> dash2 && ss >> day && !(ss >> trailing) && dash1 == '-' &&
      dash2 == '-') {
    int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (year > 0 && (month >= 1 && month <= 12)) {
      if (day <= days[month - 1] && day >= 1)
        return true;
      else if (month == 2 && day == 29) {
        if (year % 4 == 0 || (year % 100 == 0 && year % 400 == 0))
          return true;
      }
    }
  }
  std::cout << year << std::endl;
  std::cout << month << std::endl;
  std::cout << day << std::endl;

  std::cerr << "line " << n << ": Invalid date\n";
  return false;
}

bool BitcoinExchange::_check_value(int n, const std::string &value_s,
                                   float &value_f) {
  std::istringstream ss(value_s);
  char trailing;

  if (ss >> std::noskipws >> value_f && !(ss >> trailing) && value_f >= 0)
    return true;

  std::cerr << "line " << n << ": Invalid price\n";
  return false;
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
    if (_check_date(n, date) && _check_value(n, value_s, value_f))
      _database[date] = value_f;
  }
  if (n <= 1)
    throw std::runtime_error("Invalid csv");
}
