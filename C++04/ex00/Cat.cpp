#include "Cat.hpp"
#include "Animal.hpp"
#include <iostream>

Cat::Cat() :
    Animal() {
    this->_type = "Cat";
    std::cout << "Default cat constructor called" << std::endl;
}

Cat::Cat(const Cat& other) :
    Animal(other) {
    this->_type = other._type;
    std::cout << "Default cat copy constructor called" << std::endl;
}

Cat& Cat::operator=(const Cat& rhs) {
    if (this != &rhs)
        this->_type = rhs._type;
    std::cout << "Default cat copy assignment called" << std::endl;
    return *this;
}

Cat::~Cat() {
    std::cout << "Default cat destructor called" << std::endl;
};

void Cat::makeSound() const {
    std::cout << "meoww" << std::endl;
}
