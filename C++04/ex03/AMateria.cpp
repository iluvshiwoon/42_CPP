#include "AMateria.hpp"
#include "ICharacter.hpp"
#include <iostream>
#include <string>

AMateria::AMateria() {
    std::cout << "Default AMateria constructor called" << std::endl;
}

AMateria::AMateria(const std::string& type) :
    _type(type) {
    std::cout << "Default AMateria string constructor called" << std::endl;
}

AMateria::AMateria(const AMateria& other) :
    _type(other._type) {
    std::cout << "Default AMateria copy constructor called" << std::endl;
}

AMateria& AMateria::operator=(const AMateria& rhs) {
    if (this == &rhs)
        return *this;
    std::cout << "Default AMateria copy assignment called" << std::endl;
    return *this;
}

AMateria::~AMateria() {
    std::cout << "Default AMateria destructor called" << std::endl;
};

const std::string& AMateria::getType() const {
    return _type;
}

void AMateria::use(ICharacter& target) {
    if (_type == "ice")
        std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
    else if (_type == "cure")
        std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
    else
        std::cout << "* unknown material do something to " << target.getName() << " *" << std::endl;
}
