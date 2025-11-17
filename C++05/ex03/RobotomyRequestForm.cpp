#include "RobotomyRequestForm.hpp"
#include "AForm.hpp"
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
    : AForm("Robotomy Request Form", 72, 45) {
  this->_target = target;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other)
    : AForm(other) {
  this->_target = other._target;
}

RobotomyRequestForm &

RobotomyRequestForm::operator=(const RobotomyRequestForm &rhs) {
  if (this != &rhs) {
    AForm::operator=(rhs);
    this->_target = rhs._target;
  }
  return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::action() const {
  std::cout << "BRRRRRRRRRRRRRRRRR" << std::endl;
  if (std::rand() % 2) {
    std::cout << this->_target << " has been successfully robotomized"
              << std::endl;
  } else
    std::cout << "robotomy failed" << std::endl;
}
