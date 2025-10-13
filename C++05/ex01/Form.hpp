#ifndef FORM_HPP
#define FORM_HPP
#include <ostream>
#include <string>
#include "Bureaucrat.hpp"

class Form {
   private:
      bool _signed;
      const std::string _name;
      const int _requiredGrade;
      const int _executeGrade; 
   public:
      Form(const std::string& name, const int& requiredGrade, const int& executeGrade);
      Form(const Form& other);
      Form& operator=(const Form& rhs);
      ~Form();
      std::string getName() const;
      bool getSigned() const;
      int getGradeRequired() const;
      int getGradeExecute() const;
      void beSigned(const Bureaucrat& b) ;
      class GradeTooHighException : public std::exception {
         public:
            virtual const char* what() const throw() {
               return "Grade too high";
            };
      };
      class GradeTooLowException : public std::exception {
         public:
            virtual const char* what() const throw() {
               return "Grade too low";
            };
      };
};

std::ostream& operator<<(std::ostream& os, const Form& f);
#endif
