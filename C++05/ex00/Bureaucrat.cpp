#include <ostream>
#include <string>
#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string name, const int grade) : _name(name), _grade(0){
   if (grade < 1)
      throw GradeTooHighException();
   else if (grade > 150)
      throw GradeTooLowException();
   else
      _grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name), _grade(other._grade) {
}

Bureaucrat::~Bureaucrat(){}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& rhs) {
   if (this != &rhs)
      this->_grade = rhs._grade;
   return *this;
}

std::string Bureaucrat::getName() const {
   return _name;
}

int Bureaucrat::getGrade() const {
   return _grade;
}

void Bureaucrat::increaseGrade() {
   _grade-=1;
   if (_grade < 1)
      throw GradeTooHighException();
   else if (_grade > 150)
      throw GradeTooLowException();
}

void Bureaucrat::decreaseGrade() {
   _grade+=1;
   if (_grade < 1)
      throw GradeTooHighException();
   else if (_grade > 150)
      throw GradeTooLowException();
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b) {
   os << b.getName() << ", bureaucrat grade " << b.getGrade();
   return os;
}
