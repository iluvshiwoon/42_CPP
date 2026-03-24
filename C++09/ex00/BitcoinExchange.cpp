#include "BitcoinExchange.hpp"
#include <exception>
#include <fstream>
#include <ios>
#include <iostream>
#include <map>
#include <sstream>
#include <stdexcept>
#include <string>

BitcoinExchange::BitcoinExchange(const std::string &filename) {
  _parse_file("data.csv", DB, -1.0f, ",");
  _parse_file(filename, INPUT, 1000.0f, " | ");
}

BitcoinExchange::~BitcoinExchange() {};

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
    : _database(other._database) {}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &rhs) {
  if (this != &rhs) {
    this->_database = rhs._database;
  }
  return *this;
}

bool BitcoinExchange::_check_date(int n, const std::string &date,
                                  const std::string &filename) {
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
  std::cerr << "line " << n << " in " << filename << " : Invalid date => "
            << date << "\n";
  return false;
}

bool BitcoinExchange::_check_value(int n, const std::string &value_s,
                                   float &value_f, const std::string &filename,
                                   const float &limit, int mode) {
  std::istringstream ss(value_s);
  char trailing;

  if (ss >> std::noskipws >> value_f && !(ss >> trailing) && value_f >= 0 &&
      (mode == DB || value_f <= limit))
    return true;

  std::cerr << "line " << n << " in " << filename << " : Invalid value\n";
  return false;
}

bool _is_open_file(const std::string &filename, std::ifstream &istrm) {
  if (!istrm.is_open()) {
    std::cerr << filename;
    throw std::runtime_error(" failed to open\n");
  }
  return true;
}

void BitcoinExchange::_parse_file(const std::string &filename, int mode,
                                  const float &limit,
                                  const std::string &pattern) {
  std::ifstream istrm(filename.c_str());

  if (!_is_open_file(filename, istrm))
    return;

  std::string line;
  std::string date;
  std::string value_s;
  std::string::size_type i;
  float value_f;
  int n = 0;
  while (std::getline(istrm, line)) {
    if (n++ == 0)
      continue;
    i = line.find(pattern);
    if (i == std::string::npos) {
      std::cerr << "line " << n << " in " << filename << " : wrong format\n";
      continue;
    }
    date = line.substr(0, i);
    value_s = line.substr(i + pattern.length());
    if (_check_date(n, date, filename) &&
        _check_value(n, value_s, value_f, filename, limit, mode)) {
      if (mode == DB)
        _database[date] = value_f;
      else if (mode == INPUT) {
        try {
          float result = _get_rate(date) * value_f;
          std::cout << date << " => " << value_f << " = " << result << "\n";
        } catch (std::exception &e) {
          std::cerr << "line " << n << " in " << filename << e.what();
        }
      }
    }
  }
  if (mode == DB && n <= 1)
    throw std::runtime_error("Invalid csv");
}
float BitcoinExchange::_get_rate(const std::string &date) {
  std::map<std::string, float>::iterator it = this->_database.lower_bound(date);
  if (it == this->_database.begin() && it->first != date)
    throw std::out_of_range(" : rates out of range\n");
  if (it != this->_database.end() && it->first == date)
    return it->second;
  --it;
  return it->second;
}
