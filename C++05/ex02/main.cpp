#include "AForm.hpp"
#include "Bureaucrat.hpp"
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
    form = new ShrubberyCreationForm("garden");
    john.executeForm(*form);
    delete form;
  } catch (std::exception &e) {
    std::cout << "Should throw exception " << e.what() << std::endl;
    delete form;
  }
  std::cout << std::endl;
  try {
    form = new ShrubberyCreationForm("garden");
    john.signForm(*form);
    doe.executeForm(*form);
    delete form;
  } catch (std::exception &e) {
    std::cout << "Should throw exception " << e.what() << std::endl;
    delete form;
  }
  std::cout << std::endl;
  try {
    form = new ShrubberyCreationForm("garden");
    john.signForm(*form);
    john.executeForm(*form);
    delete form;
  } catch (std::exception &e) {
    std::cout << "Should not throw exception " << e.what() << std::endl;
    delete form;
  }
  std::cout << std::endl;
  try {
    form = new PresidentialPardonForm("Pork");
    john.signForm(*form);
    john.executeForm(*form);
    delete form;
  } catch (std::exception &e) {
    std::cout << "Should not throw exception " << e.what() << std::endl;
    delete form;
  }
  std::cout << std::endl;
  try {
    form = new PresidentialPardonForm("Pork");
    john.signForm(*form);
    doe.executeForm(*form);
    delete form;
  } catch (std::exception &e) {
    std::cout << "Should throw exception " << e.what() << std::endl;
    delete form;
  }
  std::cout << std::endl;
  try {
    form = new RobotomyRequestForm("Tralalero");
    john.signForm(*form);
    john.executeForm(*form);
    john.executeForm(*form);
    john.executeForm(*form);
    john.executeForm(*form);
    delete form;
  } catch (std::exception &e) {
    std::cout << "Should not throw exception " << e.what() << std::endl;
    delete form;
  }
  std::cout << std::endl;
  try {
    form = new RobotomyRequestForm("Tralalero");
    john.signForm(*form);
    doe.executeForm(*form);
    delete form;
  } catch (std::exception &e) {
    std::cout << "Should throw exception " << e.what() << std::endl;
    delete form;
  }
}
