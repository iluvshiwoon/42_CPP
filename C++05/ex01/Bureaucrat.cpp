#include "Bureaucrat.hpp"
#include <ostream>
#include <string>

Bureaucrat::Bureaucrat(const std::string name, const int grade)
    : _name(name), _grade(0) {
  if (grade < 1)
    throw GradeTooHighException();
  else if (grade > 150)
    throw GradeTooLowException();
  else
    _grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other)
    : _name(other._name), _grade(0) {
  if (other._grade < 1)
    throw GradeTooHighException();
  else if (other._grade > 150)
    throw GradeTooLowException();
  else
    _grade = other._grade;
}

Bureaucrat::~Bureaucrat() {}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &rhs) {
  if (this != &rhs) {
    if (rhs._grade < 1)
      throw GradeTooHighException();
    else if (rhs._grade > 150)
      throw GradeTooLowException();
    else
      this->_grade = rhs._grade;
  }
  return *this;
}

std::string Bureaucrat::getName() const { return _name; }

int Bureaucrat::getGrade() const { return _grade; }

void Bureaucrat::increaseGrade() {
  if (_grade - 1 < 1)
    throw GradeTooHighException();
  _grade -= 1;
}

void Bureaucrat::decreaseGrade() {
  if (_grade + 1 > 150)
    throw GradeTooLowException();
  _grade += 1;
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &b) {
  os << b.getName() << ", bureaucrat grade " << b.getGrade();
  return os;
}
