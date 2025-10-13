#include <exception>
#include <ostream>
#include <string>
#include "Form.hpp"

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
   if (_grade - 1 < 1)
      throw GradeTooHighException();
   _grade-=1;
}

void Bureaucrat::decreaseGrade() {
   if (_grade + 1 > 150)
      throw GradeTooLowException();
   _grade += 1;
}
void Bureaucrat::signForm(Form& f) {
   try {
      f.beSigned(*this);
      std::cout << *this << " signed " << f << std::endl;
   }
   catch(std::exception& e) {
      std::cout << *this << " couldn't sign " << f << " because " << e.what() << std::endl;
   }
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b) {
   os << b.getName() << ", bureaucrat grade " << b.getGrade();
   return os;
}
