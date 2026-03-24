#include "RPN.hpp"
#include <exception>
#include <iostream>

int main(int argc, char **argv) {
  if (argc != 2) {
    std::cerr << "usage: ./RPN <expression>\n";
    return 1;
  }
  try {
    RPN machine;
    machine.evaluate(std::string(argv[1]));
  } catch (std::exception &e) {
    std::cerr << e.what();
    return 1;
  }
  return 0;
}
