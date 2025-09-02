#include "Zombie.hpp"
#include <iostream>
#include <string>

Zombie::Zombie(const std::string& name){
    _name = name;
} 

Zombie::Zombie(const Zombie& other) :
    _name(other._name)
{}

Zombie& Zombie::operator=(const Zombie& rhs) {
    if (this != &rhs)
        _name = rhs._name;
    return *this;
}

Zombie::~Zombie(){
    std::cout << _name << " destroyed" << std::endl; 
}

void Zombie::setName(const std::string& name)
{
    _name = name;
}

std::string Zombie::getName() const{
    return _name;
}

void Zombie::announce() const {
    std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
