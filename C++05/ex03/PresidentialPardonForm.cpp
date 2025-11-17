#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string &target)
    : AForm("Presidential Pardon Form", 25, 5) {
  this->_target = target;
}

PresidentialPardonForm::PresidentialPardonForm(
    const PresidentialPardonForm &other)
    : AForm(other) {
  this->_target = other._target;
}

PresidentialPardonForm &

PresidentialPardonForm::operator=(const PresidentialPardonForm &rhs) {
  if (this != &rhs) {
    AForm::operator=(rhs);
    this->_target = rhs._target;
  }
  return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {}

void PresidentialPardonForm::action() const {
  std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox"
            << std::endl;
}
