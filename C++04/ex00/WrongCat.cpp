#include "WrongCat.hpp"
#include "WrongAnimal.hpp"
#include <iostream>

WrongCat::WrongCat() :
    WrongAnimal() {
    this->_type = "WrongCat";
    std::cout << "Default WrongCat constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat& other) :
    WrongAnimal(other) {
    this->_type = other._type;
    std::cout << "Default WrongCat copy constructor called" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& rhs) {
    if (this != &rhs)
        this->_type = rhs._type;
    std::cout << "Default WrongCat copy assignment called" << std::endl;
    return *this;
}

WrongCat::~WrongCat() {
    std::cout << "Default WrongCat destructor called" << std::endl;
};

void WrongCat::makeSound() const {
    std::cout << "wrong meoww" << std::endl;
}
