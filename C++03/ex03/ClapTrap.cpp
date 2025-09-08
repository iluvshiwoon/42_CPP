#include "ClapTrap.hpp"
#include <iostream>
#include <ostream>
#include <string>

ClapTrap::ClapTrap() : 
    _hitPoint(10), _energyPoint(10), _attackDamage(0) {
    std::cout << "ClapTrap default constructor called" << std::endl; 
};

ClapTrap::ClapTrap(const std::string name) :
    _name(name), _hitPoint(10), _energyPoint(10), _attackDamage(0) {
    std::cout << "ClapTrap constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other) :
    _name(other._name), _hitPoint(other._hitPoint), _energyPoint(other._energyPoint),
    _attackDamage(other._attackDamage) {
    std::cout << "ClapTrap copy constructor called" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& rhs) {
    if (this != &rhs)
    {
        _name = rhs._name;
        _hitPoint = rhs._hitPoint;
        _energyPoint = rhs._energyPoint;
        _attackDamage = rhs._attackDamage;
    }
    std::cout << "ClapTrap operator = called" << std::endl;
    return *this;
}

ClapTrap::~ClapTrap() {
    std::cout << "ClapTrap destructor called" << std::endl;
}

void ClapTrap::attack(const std::string& target) {
    if (_energyPoint > 0 && _hitPoint > 0)
    {
        std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _attackDamage << 
" points of damage!" << std::endl;
        _energyPoint -= 1;
    }
    else if (_hitPoint <= 0)
        std::cout << "ClapTrap " << _name << " is dead :(" << std::endl;
    else if (_energyPoint <= 0)
        std::cout << "ClapTrap " << _name << " is out of energy :(" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
    if (_hitPoint > 0)
    {
        std::cout << "ClapTrap " << _name << " took " << amount << " points of damage!" << std::endl;
        _hitPoint -= amount;
    }
    else if (_hitPoint <= 0)
        std::cout << "ClapTrap " << _name << " is dead :(" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (_energyPoint > 0 && _hitPoint > 0)
    {
        std::cout << "ClapTrap " << _name << " got " << amount << " points of health back!" << std::endl;
        _energyPoint -= 1;
    }
    else if (_hitPoint <= 0)
        std::cout << "ClapTrap " << _name << " is dead :(" << std::endl;
    else if (_energyPoint <= 0)
        std::cout << "ClapTrap " << _name << " is out of energy :(" << std::endl;
}
