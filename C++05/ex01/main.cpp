#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <exception>
#include <iostream>
#include <ostream>

int main() {
   try {
      Bureaucrat f("Franck", 149);
      Bureaucrat b(f);
      std::cout << f << std::endl;
      std::cout << b << std::endl;
   }
   catch(std::exception& e) {
      std::cout << "Should not throw exception" << e.what() << std::endl;
   }
   try {
      Bureaucrat f("Franck", 149);
      Bureaucrat b(f);
      f.decreaseGrade();
      b.increaseGrade();
      std::cout << f << std::endl;
      std::cout << b << std::endl;
   }
   catch(std::exception& e) {
      std::cout << "Should not throw exception" << e.what() << std::endl;
   }
   try {
      Bureaucrat f("Franck", 151);
      Bureaucrat k("Jack", 0);
      Bureaucrat b = f;
      std::cout << f << std::endl;
      std::cout << b << std::endl;
   }
   catch(std::exception& e) {
      std::cout << "Should throw exception" << e.what() << std::endl;
   }
   try {
      Bureaucrat f("Franck", 150);
      Bureaucrat k("Jack", 1);
      Bureaucrat b = f;
      k.increaseGrade();
      f.decreaseGrade();
      std::cout << f << std::endl;
      std::cout << b << std::endl;
   }
   catch(std::exception& e) {
      std::cout << "Should throw exception" << e.what() << std::endl;
   }
   Bureaucrat john("John", 4);
   Bureaucrat doe("Doe", 15);
   try {
      Form chart("Chart", 5, 4);
      john.signForm(chart);
   }
   catch (std::exception& e) {
      std::cout << "Should not throw exception" << e.what() << std::endl;
   }
   try {
      Form chart("Chart", 5, 4);
      doe.signForm(chart);
   }
   catch (std::exception& e) {
      std::cout << "Should throw exception" << e.what() << std::endl;
   }
   try {
      Form right("Right", 1, 1);
      Form wrong("Wrong", 0, 0);
   }
   catch (std::exception& e) {
      std::cout << "Should throw exception" << e.what() << std::endl;
   }

}
