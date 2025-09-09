#include "Ice.hpp"
#include "AMateria.hpp"
#include <iostream>
#include <string>

Ice::Ice() : AMateria("ice") {
    std::cout << "Default Ice constructor called" << std::endl;
}

Ice::Ice(const Ice& other) : AMateria(other) {
    std::cout << "Default Ice copy constructor called" << std::endl;
}

Ice& Ice::operator=(const Ice& rhs) {
    if (this == &rhs)
        return *this;
    std::cout << "Default Ice copy assignment called" << std::endl;
    return *this;
}

Ice::~Ice() {
    std::cout << "Default Ice destructor called" << std::endl;
};

Ice* Ice::clone() const {
    return new Ice(*this);
}
