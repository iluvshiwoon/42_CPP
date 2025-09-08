#include "ClapTrap.hpp"
#include <iostream>
#include <ostream>
#include <string>

ClapTrap::ClapTrap() : 
    _hitPoint(10), _energyPoint(10), _attackDamage(0) {
    std::cout << "Default constructor called" << std::endl; 
};

ClapTrap::ClapTrap(const std::string name) :
    _name(name), _hitPoint(10), _energyPoint(10), _attackDamage(0) {
    std::cout << "Constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other) :
    _name(other._name), _hitPoint(other._hitPoint), _energyPoint(other._energyPoint),
    _attackDamage(other._attackDamage) {
    std::cout << "Copy constructor called" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& rhs) {
    if (this != &rhs)
    {
        _name = rhs._name;
        _hitPoint = rhs._hitPoint;
        _energyPoint = rhs._energyPoint;
        _attackDamage = rhs._attackDamage;
    }
    return *this;
}

ClapTrap::~ClapTrap() {
    std::cout << "Destructor called" << std::endl;
}

void ClapTrap::attack(const std::string& target) {
    std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _attackDamage << 
" points of damage!" << std::endl;
    _energyPoint -= 1;
}

void ClapTrap::takeDamage(unsigned int amount) {
    std::cout << "ClapTrap " << _name << " took " << amount << " points of damage!" << std::endl;
    _hitPoint -= amount;
}

void ClapTrap::beRepaired(unsigned int amount) {
    std::cout << "ClapTrap " << _name << " got " << amount << " points of health back!" << std::endl;
    _energyPoint -= 1;
}
