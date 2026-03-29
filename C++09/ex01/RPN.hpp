#ifndef RPN_HPP
#define RPN_HPP
#include <stack>
#include <string>
class RPN {
private:
  void _process_ops(std::stack<int> &tokens, const std::string &token);

public:
  RPN();
  ~RPN();

  void evaluate(const std::string &expr);
};
#endif
