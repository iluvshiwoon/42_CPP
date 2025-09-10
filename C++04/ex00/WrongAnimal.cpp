#include "WrongAnimal.hpp"
#include <iostream>
#include <string>

WrongAnimal::WrongAnimal() {
    std::cout << "Default WrongAnimal constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const std::string& type) :
    _type(type) {
    std::cout << "Default WrongAnimal string constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other) :
    _type(other._type) {
    std::cout << "Default WrongAnimal copy constructor called" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& rhs) {
    if (this != &rhs)
        this->_type = rhs._type;
    std::cout << "Default WrongAnimal copy assignment called" << std::endl;
    return *this;
}

WrongAnimal::~WrongAnimal() {
    std::cout << "Default WrongAnimal destructor called" << std::endl;
};

void WrongAnimal::makeSound() const {
    std::cout << "wrong grrr" << std::endl;
}

std::string WrongAnimal::getType() const {
    return this->_type;
}
