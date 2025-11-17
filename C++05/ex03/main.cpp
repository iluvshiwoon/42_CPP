#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <cstdlib>
#include <ctime>
#include <exception>
#include <iostream>
#include <ostream>

int main() {
  std::srand(std::time(NULL));
  Bureaucrat john("John", 4);
  Bureaucrat doe("Doe", 150);
  AForm *form = NULL;
  try {
    form = Intern().makeForm("Shrubbery CreationForm ", "soil");
    john.executeForm(*form);
    delete form;
  } catch (std::exception &e) {
    std::cout << "Should throw exception " << e.what() << std::endl;
    delete form;
  }
  try {
    form = Intern().makeForm("Shrubbery Creation Form", "soil");
    john.signForm(*form);
    john.executeForm(*form);
    delete form;
  } catch (std::exception &e) {
    std::cout << "Should not throw exception " << e.what() << std::endl;
    delete form;
  }
}
