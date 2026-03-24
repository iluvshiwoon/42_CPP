#include "BitcoinExchange.hpp"
#include <iostream>
int main(int argc, char **argv) {
  if (argc == 2)
    try {
      BitcoinExchange(std::string(argv[1]));
      return 0;
    } catch (std::exception &e) {
      std::cerr << e.what();
    }
  else {
    std::cerr << "No input file!\nUsage: ./btc <input>\n";
    return 1;
  }
}
