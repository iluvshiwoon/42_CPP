#ifndef AFORM_HPP
#define AFORM_HPP
#include "Bureaucrat.hpp"
#include <ostream>
#include <string>

class AForm {
private:
  bool _signed;
  const std::string _name;
  const int _requiredGrade;
  const int _executeGrade;
  virtual void action() const = 0;

public:
  AForm(const std::string &name, const int &requiredGrade,
        const int &executeGrade);
  AForm(const AForm &other);
  AForm &operator=(const AForm &rhs);
  virtual ~AForm();
  std::string getName() const;
  bool getSigned() const;
  int getGradeRequired() const;
  int getGradeExecute() const;
  void beSigned(const Bureaucrat &b);
  void execute(const Bureaucrat &executor) const;
  class GradeTooHighException : public std::exception {
  public:
    virtual const char *what() const throw() { return "Grade too high"; };
  };
  class GradeTooLowException : public std::exception {
  public:
    virtual const char *what() const throw() { return "Grade too low"; };
  };
  class NotSigned : public std::exception {
  public:
    virtual const char *what() const throw() { return "Not Signed"; };
  };
};

std::ostream &operator<<(std::ostream &os, const AForm &f);
#endif
