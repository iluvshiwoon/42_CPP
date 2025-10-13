#include <algorithm>
#include <iostream>
#include <ostream>
#include <string>
#include "Form.hpp"

Form::Form (const std::string& name, const int& requiredGrade, const int& executeGrade) :
   _signed(false),
   _name(name), 
   _requiredGrade(requiredGrade), 
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

Form::~Form(){}

Form::Form(const Form& other) :
   _signed(other._signed),  
   _name(other._name),
   _requiredGrade(other._requiredGrade),
   _executeGrade(other._executeGrade) {
      if (_requiredGrade < 1)
         throw GradeTooHighException();
      else if (_requiredGrade > 150)
         throw GradeTooLowException();
      if (_executeGrade < 1)
         throw GradeTooHighException();
      else if (_executeGrade > 150)
         throw GradeTooLowException();
}

Form& Form::operator=(const Form& rhs) {
   if (this != &rhs)
      _signed = rhs._signed;
   return *this;
}
std::string Form::getName() {
   return _name;
}
bool Form::getSigned() {
   return _signed;
}

int Form::getGradeExecute() {
   return _executeGrade;
}

int Form::getGradeRequired() {
   return _requiredGrade;
}

void Form::beSigned(const Bureaucrat& b) {
   if (b.getGrade() > _requiredGrade)
      throw GradeTooLowException();
   else
      _signed = true;
}

std::ostream& operator<<(std::ostream& os, Form& f) {
   std::cout << "Form: " << f.getName() << " is signed: " << f.getSigned() <<\
      " required grade to sign: " << f.getGradeRequired() << " required grade to execute: " << f.getGradeExecute();
   return os;
}
