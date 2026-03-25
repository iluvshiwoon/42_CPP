#include "BitcoinExchange.hpp"
#include <iostream>
int main(int argc, char **argv) {
  if (argc == 2)
    try {
      BitcoinExchange exchange("data.csv");
      exchange.evaluateInput(argv[1]);
      return 0;
    } catch (std::exception &e) {
      std::cerr << e.what();
      return 1;
    }
  else {
    std::cerr << "Usage: ./btc <input>\n";
    return 1;
  }
}
