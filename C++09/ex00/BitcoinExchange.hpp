#ifndef BITCOIN_EXCHANGE_HPP
#define BITCOIN_EXCHANGE_HPP
#include <map>
#include <string>
class BitcoinExchange {
private:
  std::map<std::string, float> _database;
  void _load_database(const std::string &filename);
  bool _check_date(int n, const std::string &date);
  bool _check_value(int n, const std::string &value, float &value_f);
  float _get_rate(const std::string &date);

public:
  BitcoinExchange();
  BitcoinExchange(const BitcoinExchange &other);
  BitcoinExchange &operator=(const BitcoinExchange &rhs);
  ~BitcoinExchange();
};
#endif
