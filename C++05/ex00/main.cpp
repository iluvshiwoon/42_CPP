#include "Bureaucrat.hpp"
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
}
