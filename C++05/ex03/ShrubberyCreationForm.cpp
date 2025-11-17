#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
    : AForm("Shrubbery Creation Form", 145, 137) {
  this->_target = target;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
    : AForm(other) {
  this->_target = other._target;
}

ShrubberyCreationForm &

ShrubberyCreationForm::operator=(const ShrubberyCreationForm &rhs) {
  if (this != &rhs) {
    AForm::operator=(rhs);
    this->_target = rhs._target;
  }
  return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::action() const {
  std::string filename(this->_target + "_shrubbery");
  std::ofstream outfile((filename.c_str()));
  if (!outfile.is_open()) {
    std::cerr << "Failed to open: " << filename << std::endl;
  }
  outfile << "         v\n"
             "        >X<\n"
             "         A\n"
             "        d$b\n"
             "      .d\\$$b.\n"
             "    .d$i$$\\$$b.\n"
             "       d$$@b\n"
             "      d\\$$$ib\n"
             "    .d$$$\\$$$b\n"
             "  .d$$@$$$$\\$$ib.\n"
             "      d$$i$$b\n"
             "     d\\$$$$@$b\n"
             "  .d$@$$\\$$$$$*b.\n"
             "         }\n"
             "         }\n"
             "        /__\\\n";
  if (outfile.fail()) {
    std::cerr << "Write failed" << std::endl;
  }
}
