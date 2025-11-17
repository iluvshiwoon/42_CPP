#include "Intern.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iterator>
#include <string>

Intern::Intern() {}
Intern::~Intern() {};

static AForm *createShrubbery(const std::string &target) {
  return new ShrubberyCreationForm(target);
}

static AForm *requestRobotomy(const std::string &target) {
  return new RobotomyRequestForm(target);
}

static AForm *createPardon(const std::string &target) {
  return new PresidentialPardonForm(target);
}

static struct FormCreator {
  const char *name;
  AForm *(*constructor)(const std::string &target);
} formTable[] = {
    {"Shrubbery Creation Form", &createShrubbery},
    {"Robotomy Request Form", &requestRobotomy},
    {"Presidential Pardon Form", &createPardon},
};

AForm *Intern::makeForm(const std::string &name,
                        const std::string &target) const {
  static const std::size_t COUNT = sizeof(formTable) / sizeof(formTable[0]);
  for (std::size_t i = 0; i < COUNT; i++) {
    if (name == formTable[i].name) {
      std::cout << "Intern creates " << name << std::endl;
      return formTable[i].constructor(target);
    }
  }
  std::cerr << "Form: " << name << " not found" << std::endl;
  throw UnknownForm();
}
