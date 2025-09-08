#include "Cat.hpp"
#include "Animal.hpp"
#include "Brain.hpp"
#include <iostream>

Cat::Cat() :
    Animal() {
    this->_brain = new Brain();
    this->_type = "Cat";
    std::cout << "Default cat constructor called" << std::endl;
}

Cat::Cat(const Cat& other) :
    Animal(other) {
    this->_brain = new Brain(*other._brain);
    this->_type = other._type;
    std::cout << "Default cat copy constructor called" << std::endl;
}

Cat& Cat::operator=(const Cat& rhs) {
    if (this != &rhs) {
        delete this->_brain;
        this->_brain = new Brain(*rhs._brain);
        _type = rhs._type;
    }
    std::cout << "Default cat copy assignment called" << std::endl;
    return *this;
}

Cat::~Cat() {
    delete this->_brain;
    std::cout << "Default cat destructor called" << std::endl;
};

void Cat::makeSound() const {
    std::cout << "meoww" << std::endl;
}
