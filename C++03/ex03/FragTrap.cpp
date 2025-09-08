#include "FragTrap.hpp"
#include "ClapTrap.hpp"
#include <iostream>
#include <string>

FragTrap::FragTrap() :
    ClapTrap() {
    this->_hitPoint = 100;
    this->_energyPoint = 100;
    this->_attackDamage = 30;

    std::cout << "FragTrap default constructor called" << std::endl;
}

FragTrap::FragTrap(const std::string name) : 
    ClapTrap(name) {
    this->_hitPoint = 100;
    this->_energyPoint = 100;
    this->_attackDamage = 30;

    std::cout << "FragTrap constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap& other) :
    ClapTrap(other._name) {
    this->_hitPoint = 100;
    this->_energyPoint = 100;
    this->_attackDamage = 30;

    std::cout << "FragTrap copy constructor called" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& rhs) {
    if (this != &rhs)
    {
        _name = rhs._name;
        _hitPoint = rhs._hitPoint;
        _energyPoint = rhs._energyPoint;
        _attackDamage = rhs._attackDamage;
    }
    std::cout << "FragTrap operator = called" << std::endl;
    return *this;
}
FragTrap::~FragTrap() { std::cout << "FragTrap destructor called" << std::endl; }

void FragTrap::attack(const std::string& target) {
    if (_energyPoint > 0 && _hitPoint > 0)
    {
        std::cout << "FragTrap " << _name << " attacks " << target << ", causing " << _attackDamage << 
" points of damage!" << std::endl;
        _energyPoint -= 1;
    }
    else if (_hitPoint <= 0)
        std::cout << "FragTrap " << _name << " is dead :(" << std::endl;
    else if (_energyPoint <= 0)
        std::cout << "FragTrap " << _name << " is out of energy :(" << std::endl;
}

void FragTrap::takeDamage(unsigned int amount) {
    if (_hitPoint > 0)
    {
        std::cout << "FragTrap " << _name << " took " << amount << " points of damage!" << std::endl;
        _hitPoint -= amount;
    }
    else if (_hitPoint <= 0)
        std::cout << "FragTrap " << _name << " is dead :(" << std::endl;
}

void FragTrap::beRepaired(unsigned int amount) {
    if (_energyPoint > 0 && _hitPoint > 0)
    {
        std::cout << "FragTrap " << _name << " got " << amount << " points of health back!" << std::endl;
        _energyPoint -= 1;
        _hitPoint += amount;
    }
    else if (_hitPoint <= 0)
        std::cout << "FragTrap " << _name << " is dead :(" << std::endl;
    else if (_energyPoint <= 0)
        std::cout << "FragTrap " << _name << " is out of energy :(" << std::endl;
}

void FragTrap::highFiveGuys() {
    if (_energyPoint > 0 && _hitPoint > 0)
    {
        std::cout << "FragTrap " << _name << " raise it's arm for a high five!" << std::endl;
        _energyPoint -= 1;
    }
    else if (_hitPoint <= 0)
        std::cout << "FragTrap " << _name << " is dead :(" << std::endl;
    else if (_energyPoint <= 0)
        std::cout << "FragTrap " << _name << " is out of energy :(" << std::endl;
}
