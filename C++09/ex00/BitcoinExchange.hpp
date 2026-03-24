#ifndef BITCOIN_EXCHANGE_HPP
#define BITCOIN_EXCHANGE_HPP
#include <map>
#include <string>
class BitcoinExchange {
private:
  enum _mode { DB, INPUT };
  std::map<std::string, float> _database;
  void _load_database(const std::string &filename);
  bool _check_date(int n, const std::string &date, const std::string &filename);
  bool _check_value(int n, const std::string &value_s, float &value_f,
                    const std::string &filename, const float &limit);
  float _get_rate(const std::string &date);
  void _execute(const std::string &filename);
  void _parse_file(const std::string &filename, int mode, const float &limit,
                   const std::string &pattern);

public:
  BitcoinExchange(const std::string &filename);
  BitcoinExchange(const BitcoinExchange &other);
  BitcoinExchange &operator=(const BitcoinExchange &rhs);
  ~BitcoinExchange();
};
#endif
