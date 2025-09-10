#include "Dog.hpp"
#include "Animal.hpp"
#include <iostream>

Dog::Dog() : 
    Animal() {
    this->_type = "Dog";
    std::cout << "Default Dog constructor called" << std::endl;
}

Dog::Dog(const Dog& other) :
    Animal(other) {
    this->_type = other._type;
    std::cout << "Default Dog copy constructor called" << std::endl;
}

Dog& Dog::operator=(const Dog& rhs) {
    if (this != &rhs)
        this->_type = rhs._type;
    std::cout << "Default Dog copy assignment called" << std::endl;
    return *this;
}

Dog::~Dog() {
    std::cout << "Default Dog destructor called" << std::endl;
};

void Dog::makeSound() const {
    std::cout << "bark bark" << std::endl;
}
