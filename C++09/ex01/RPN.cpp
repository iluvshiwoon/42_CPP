#include "RPN.hpp"
#include <cctype>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>

void RPN::_process_ops(const std::string &token) {
  if (this->_tokens.size() < 2) {
    std::cerr << "unexpected token : ";
    throw std::runtime_error(token + "\n");
  }
  char op = token[0];
  const int a = this->_tokens.top();
  // std::cout << "A: " << a << std::endl;
  this->_tokens.pop();
  const int b = this->_tokens.top();
  // std::cout << "B: " << b << std::endl;
  this->_tokens.pop();
  if (op == '+')
    this->_tokens.push(a + b);
  else if (op == '-')
    this->_tokens.push(b - a);
  else if (op == '/') {
    if (a == 0)
      throw std::runtime_error("tried to divide by 0\n");
    this->_tokens.push(b / a);
  } else if (op == '*')
    this->_tokens.push(a * b);
  // std::cout << "After: " << token << " : " << this->_tokens.top() <<
  // std::endl;
}

void RPN::evaluate(const std::string &expr) {
  std::istringstream ss(expr);

  std::string token;
  std::string valid_ops("+-/*");
  bool is_ops;
  this->_tokens = std::stack<int>();
  while (ss >> token) {
    is_ops = (valid_ops.find(token) != std::string::npos);
    if (token.length() != 1 || (!std::isdigit(token[0]) && is_ops == false)) {
      std::cerr << token;
      throw std::runtime_error(" : wrong token in expr\n");
    }
    if (is_ops == true)
      this->_process_ops(token);
    else
      this->_tokens.push(std::atoi(token.c_str()));
  }
  if (this->_tokens.size() != 1)
    throw std::runtime_error("invalid RPN expression\n");
  std::cout << this->_tokens.top() << std::endl;
}

RPN::RPN() {}

RPN::~RPN() {}

RPN::RPN(const RPN &other) : _tokens(other._tokens) {}

RPN &RPN::operator=(const RPN &rhs) {
  if (this != &rhs)
    this->_tokens = rhs._tokens;
  return *this;
}
