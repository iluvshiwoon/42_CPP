#ifndef ROBOTOMY_REQUEST_FORM_HPP
#define ROBOTOMY_REQUEST_FORM_HPP
#include "AForm.hpp"
#include <string>
#endif

class RobotomyRequestForm : public AForm {
private:
  void action() const;
  std::string _target;

public:
  RobotomyRequestForm(const std::string &target);
  RobotomyRequestForm(const RobotomyRequestForm &other);
  RobotomyRequestForm &operator=(const RobotomyRequestForm &rhs);
  ~RobotomyRequestForm();
};
