#include "Dog.hpp"
#include "Animal.hpp"
#include "Brain.hpp"
#include <iostream>

Dog::Dog() : 
    Animal() {
    _brain = new Brain();
    this->_type = "Dog";
    std::cout << "Default Dog constructor called" << std::endl;
}

Dog::Dog(const Dog& other) :
    Animal(other) {
    _brain = new Brain(*other._brain);
    this->_type = other._type;
    std::cout << "Default Dog copy constructor called" << std::endl;
}

Dog& Dog::operator=(const Dog& rhs) {
    if (this != &rhs)
    {
        delete this->_brain;
        this->_brain = new Brain(*rhs._brain);
        _type = rhs._type;
    }
    std::cout << "Default Dog copy assignment called" << std::endl;
    return *this;
}

Dog::~Dog() {
    delete this->_brain;
    std::cout << "Default Dog destructor called" << std::endl;
};

void Dog::makeSound() const {
    std::cout << "bark bark" << std::endl;
}
