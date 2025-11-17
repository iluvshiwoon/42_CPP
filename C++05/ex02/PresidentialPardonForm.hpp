#ifndef PRESIDENTIAL_PARDON_FORM_HPP
#define PRESIDENTIAL_PARDON_FORM_HPP
#include "AForm.hpp"
#include <string>
#endif

class PresidentialPardonForm : public AForm {
private:
  void action() const;
  std::string _target;

public:
  PresidentialPardonForm(const std::string &target);
  PresidentialPardonForm(const PresidentialPardonForm &other);
  PresidentialPardonForm &operator=(const PresidentialPardonForm &rhs);
  ~PresidentialPardonForm();
};
