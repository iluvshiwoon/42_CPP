#include "Character.hpp"
#include "AMateria.hpp"
#include <iostream>
#include <string>

ICharacter::ICharacter() {
    std::cout << "Default ICharacter constructor called" << std::endl;
}

ICharacter::ICharacter(const std::string& name) : _name(name) {
    std::cout << "Default ICharacter string constructor called" << std::endl;
}

ICharacter::ICharacter(const ICharacter& other) : _name(other._name) {
    for (int i = 0; i < 4; i++)
        _inventory[i] = new AMateria(*other._inventory[i])
    std::cout << "Default ICharacter copy constructor called" << std::endl;
}

ICharacter& ICharacter::operator=(const ICharacter& rhs) {
    if (this == &rhs)
        return *this;
    std::cout << "Default ICharacter copy assignment called" << std::endl;
    return *this;
}

ICharacter::~ICharacter() {
    std::cout << "Default ICharacter destructor called" << std::endl;
};



