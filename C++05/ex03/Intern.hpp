#ifndef INTERN_HPP
#define INTERN_HPP
#include "AForm.hpp"
#include <exception>
#include <string>

class Intern {
private:
  Intern(const Intern &other);
  Intern &operator=(const Intern &rhs);

public:
  Intern();
  ~Intern();

  AForm *makeForm(const std::string &name, const std::string &target) const;
  class UnknownForm : public std::exception {
    virtual const char *what() const throw() { return "Unknown Form"; };
  };
};

#endif
