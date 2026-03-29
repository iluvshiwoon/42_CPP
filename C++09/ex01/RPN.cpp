#include "RPN.hpp"
#include <cctype>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>

void RPN::_process_ops(std::stack<int> &tokens, const std::string &token) {
  if (tokens.size() < 2) {
    std::cerr << "unexpected token : ";
    throw std::runtime_error(token + "\n");
  }
  char op = token[0];
  const int a = tokens.top();
  // std::cout << "A: " << a << std::endl;
  tokens.pop();
  const int b = tokens.top();
  // std::cout << "B: " << b << std::endl;
  tokens.pop();
  if (op == '+')
    tokens.push(a + b);
  else if (op == '-')
    tokens.push(b - a);
  else if (op == '/') {
    if (a == 0)
      throw std::runtime_error("tried to divide by 0\n");
    tokens.push(b / a);
  } else if (op == '*')
    tokens.push(a * b);
  // std::cout << "After: " << token << " : " << tokens.top() <<
  // std::endl;
}

void RPN::evaluate(const std::string &expr) {
  std::istringstream ss(expr);

  std::string token;
  std::string valid_ops("+-/*");
  bool is_ops;
  std::stack<int> tokens;
  while (ss >> token) {
    is_ops = (valid_ops.find(token) != std::string::npos);
    if (token.length() != 1 || (!std::isdigit(token[0]) && is_ops == false)) {
      std::cerr << token;
      throw std::runtime_error(" : wrong token in expr\n");
    }
    if (is_ops == true)
      this->_process_ops(tokens, token);
    else
      tokens.push(std::atoi(token.c_str()));
  }
  if (tokens.size() != 1)
    throw std::runtime_error("invalid RPN expression\n");
  std::cout << tokens.top() << std::endl;
}

RPN::RPN() {}

RPN::~RPN() {}
