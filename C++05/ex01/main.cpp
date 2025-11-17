#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <exception>
#include <iostream>
#include <ostream>

int main() {
  Bureaucrat john("John", 4);
  Bureaucrat doe("Doe", 15);
  try {
    Form chart("Chart", 5, 4);
    john.signForm(chart);
  } catch (std::exception &e) {
    std::cout << "Should not throw exception " << e.what() << std::endl;
  }
  try {
    Form chart("Chart", 5, 4);
    doe.signForm(chart);
  } catch (std::exception &e) {
    std::cout << "Should throw exception " << e.what() << std::endl;
  }
  try {
    Form right("Right", 1, 1);
    Form wrong("Wrong", 0, 0);
  } catch (std::exception &e) {
    std::cout << "Should throw exception " << e.what() << std::endl;
  }
}
