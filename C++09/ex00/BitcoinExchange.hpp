#ifndef BITCOIN_EXCHANGE_HPP
#define BITCOIN_EXCHANGE_HPP
#include <map>
#include <string>
class BitcoinExchange {
private:
  std::map<std::string, double> _database; // do I need Compare ?
  void _load_database(std::string filename);
  bool _is_valid_database();

public:
  BitcoinExchange();
  BitcoinExchange(const BitcoinExchange &other);
  BitcoinExchange &operator=(const BitcoinExchange &rhs);
  ~BitcoinExchange();
};
#endif
