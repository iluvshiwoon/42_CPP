#include "Animal.hpp"
#include <iostream>
#include <string>

Animal::Animal() {
    std::cout << "Default animal constructor called" << std::endl;
}

Animal::Animal(const std::string& type) :
    _type(type) {
    std::cout << "Default animal string constructor called" << std::endl;
}

Animal::Animal(const Animal& other) :
    _type(other._type) {
    std::cout << "Default animal copy constructor called" << std::endl;
}

Animal& Animal::operator=(const Animal& rhs) {
    if (this != &rhs)
        _type = rhs._type;
    std::cout << "Default animal copy assignment called" << std::endl;
    return *this;
}

Animal::~Animal() {
    std::cout << "Default animal destructor called" << std::endl;
};

void Animal::makeSound() const {
    std::cout << "grrr" << std::endl;
}

std::string Animal::getType() const {
    return _type;
}
