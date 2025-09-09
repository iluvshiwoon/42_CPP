#include "Cure.hpp"
#include "AMateria.hpp"
#include <iostream>
#include <string>

Cure::Cure() : AMateria("cure") {
    std::cout << "Default Cure constructor called" << std::endl;
}

Cure::Cure(const Cure& other) : AMateria(other) {
    std::cout << "Default Cure copy constructor called" << std::endl;
}

Cure& Cure::operator=(const Cure& rhs) {
    if (this == &rhs)
        return *this;
    std::cout << "Default Cure copy assignment called" << std::endl;
    return *this;
}

Cure::~Cure() {
    std::cout << "Default Cure destructor called" << std::endl;
};

Cure* Cure::clone() const {
    return new Cure(*this);
}
