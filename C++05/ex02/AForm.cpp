#include "AForm.hpp"
#include <algorithm>
#include <iostream>
#include <ostream>
#include <string>

AForm::AForm(const std::string &name, const int &requiredGrade,
             const int &executeGrade)
    : _signed(false), _name(name), _requiredGrade(requiredGrade),
      _executeGrade(executeGrade) {
  if (requiredGrade < 1)
    throw GradeTooHighException();
  else if (requiredGrade > 150)
    throw GradeTooLowException();
  if (executeGrade < 1)
    throw GradeTooHighException();
  else if (executeGrade > 150)
    throw GradeTooLowException();
}

AForm::~AForm() {}

AForm::AForm(const AForm &other)
    : _signed(other._signed), _name(other._name),
      _requiredGrade(other._requiredGrade), _executeGrade(other._executeGrade) {
  if (_requiredGrade < 1)
    throw GradeTooHighException();
  else if (_requiredGrade > 150)
    throw GradeTooLowException();
  if (_executeGrade < 1)
    throw GradeTooHighException();
  else if (_executeGrade > 150)
    throw GradeTooLowException();
}

AForm &AForm::operator=(const AForm &rhs) {
  if (this != &rhs) {
    if (rhs._requiredGrade < 1)
      throw GradeTooHighException();
    else if (rhs._requiredGrade > 150)
      throw GradeTooLowException();
    if (rhs._executeGrade < 1)
      throw GradeTooHighException();
    else if (rhs._executeGrade > 150)
      throw GradeTooLowException();
    _signed = rhs._signed;
  }
  return *this;
}
std::string AForm::getName() const { return _name; }
bool AForm::getSigned() const { return _signed; }

int AForm::getGradeExecute() const { return _executeGrade; }

int AForm::getGradeRequired() const { return _requiredGrade; }

void AForm::beSigned(const Bureaucrat &b) {
  if (b.getGrade() > _requiredGrade)
    throw GradeTooLowException();
  else
    _signed = true;
}

void AForm::execute(const Bureaucrat &executor) const {
  if (this->getSigned() == false)
    throw NotSigned();
  else if (this->getSigned() &&
           executor.getGrade() <= this->getGradeExecute()) {
    this->action();
  } else
    throw GradeTooLowException();
}

std::ostream &operator<<(std::ostream &os, const AForm &f) {
  os << "AForm: " << f.getName() << " is signed: " << f.getSigned()
     << " required grade to sign: " << f.getGradeRequired()
     << " required grade to execute: " << f.getGradeExecute();
  return os;
}
