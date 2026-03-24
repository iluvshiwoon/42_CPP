#ifndef RPN_HPP
#define RPN_HPP
#include <stack>
#include <string>
class RPN {
private:
  std::stack<int> _tokens;
  void _process_ops(const std::string &token);

public:
  RPN();
  RPN(const RPN &other);
  RPN &operator=(const RPN &rhs);
  ~RPN();

  void evaluate(const std::string &expr);
};
#endif
