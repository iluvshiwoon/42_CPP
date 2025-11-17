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
  try {
    AForm *form = new ShrubberyCreationForm("garden");
    john.executeForm(*form);
  } catch (std::exception &e) {
    std::cout << "Should throw exception " << e.what() << std::endl;
  }
  std::cout << std::endl;
  try {
    AForm *form = new ShrubberyCreationForm("garden");
    john.signForm(*form);
    doe.executeForm(*form);
  } catch (std::exception &e) {
    std::cout << "Should throw exception " << e.what() << std::endl;
  }
  std::cout << std::endl;
  try {
    AForm *form = new ShrubberyCreationForm("garden");
    john.signForm(*form);
    john.executeForm(*form);
  } catch (std::exception &e) {
    std::cout << "Should not throw exception " << e.what() << std::endl;
  }
  std::cout << std::endl;
  try {
    AForm *form = new PresidentialPardonForm("Pork");
    john.signForm(*form);
    john.executeForm(*form);
  } catch (std::exception &e) {
    std::cout << "Should not throw exception " << e.what() << std::endl;
  }
  std::cout << std::endl;
  try {
    AForm *form = new PresidentialPardonForm("Pork");
    john.signForm(*form);
    doe.executeForm(*form);
  } catch (std::exception &e) {
    std::cout << "Should throw exception " << e.what() << std::endl;
  }
  std::cout << std::endl;
  try {
    AForm *form = new RobotomyRequestForm("Tralalero");
    john.signForm(*form);
    john.executeForm(*form);
    john.executeForm(*form);
    john.executeForm(*form);
    john.executeForm(*form);
  } catch (std::exception &e) {
    std::cout << "Should not throw exception " << e.what() << std::endl;
  }
  std::cout << std::endl;
  try {
    AForm *form = new RobotomyRequestForm("Tralalero");
    john.signForm(*form);
    doe.executeForm(*form);
  } catch (std::exception &e) {
    std::cout << "Should throw exception " << e.what() << std::endl;
  }
}
