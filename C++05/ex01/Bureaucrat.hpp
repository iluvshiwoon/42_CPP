#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP
#include <iostream>
#include <ostream>
#include <string>

class Form;

class Bureaucrat {
private:
  const std::string _name;
  int _grade;

public:
  Bureaucrat(const std::string name, const int grade);
  Bureaucrat(const Bureaucrat &other);
  Bureaucrat &operator=(const Bureaucrat &rhs);
  ~Bureaucrat();
  std::string getName() const;
  int getGrade() const;
  void increaseGrade();
  void decreaseGrade();
  class GradeTooHighException : public std::exception {
  public:
    virtual const char *what() const throw() { return "Grade too high"; };
  };
  class GradeTooLowException : public std::exception {
  public:
    virtual const char *what() const throw() { return "Grade too low"; };
  };
  void signForm(Form &f);
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &b);
#endif
