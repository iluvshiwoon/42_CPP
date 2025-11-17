#ifndef SHRUBBERY_CREATION_FORM_HPP
#define SHRUBBERY_CREATION_FORM_HPP
#include "AForm.hpp"
#include <string>

class ShrubberyCreationForm : public AForm {
private:
  void action() const;
  std::string _target;

public:
  ShrubberyCreationForm(const std::string &target);
  ShrubberyCreationForm(const ShrubberyCreationForm &other);
  ShrubberyCreationForm &operator=(const ShrubberyCreationForm &rhs);
  ~ShrubberyCreationForm();
};
#endif
