#include "ScavTrap.hpp"
#include "ClapTrap.hpp"
#include <iostream>
#include <string>

ScavTrap::ScavTrap() :
    ClapTrap() {
    this->_hitPoint = 100;
    this->_energyPoint = 50;
    this->_attackDamage = 20;

    std::cout << "ScavTrap default constructor called" << std::endl;
}

ScavTrap::ScavTrap(const std::string name) : 
    ClapTrap(name) {
    this->_hitPoint = 100;
    this->_energyPoint = 50;
    this->_attackDamage = 20;

    std::cout << "ScavTrap constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other) :
    ClapTrap(other) {

    std::cout << "ScavTrap copy constructor called" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& rhs) {
    if (this != &rhs)
    {
        _name = rhs._name;
        _hitPoint = rhs._hitPoint;
        _energyPoint = rhs._energyPoint;
        _attackDamage = rhs._attackDamage;
    }
    std::cout << "ScavTrap operator = called" << std::endl;
    return *this;
}
ScavTrap::~ScavTrap() { std::cout << "ScavTrap destructor called" << std::endl; }

void ScavTrap::attack(const std::string& target) {
    if (_energyPoint > 0 && _hitPoint > 0)
    {
        std::cout << "ScavTrap " << _name << " attacks " << target << ", causing " << _attackDamage << 
" points of damage!" << std::endl;
        _energyPoint -= 1;
    }
    else if (_hitPoint <= 0)
        std::cout << "ScavTrap " << _name << " is dead :(" << std::endl;
    else if (_energyPoint <= 0)
        std::cout << "ScavTrap " << _name << " is out of energy :(" << std::endl;
}

void ScavTrap::takeDamage(unsigned int amount) {
    if (_hitPoint > 0)
    {
        std::cout << "ScavTrap " << _name << " took " << amount << " points of damage!" << std::endl;
        _hitPoint -= amount;
    }
    else if (_hitPoint <= 0)
        std::cout << "ScavTrap " << _name << " is dead :(" << std::endl;
}

void ScavTrap::beRepaired(unsigned int amount) {
    if (_energyPoint > 0 && _hitPoint > 0)
    {
        std::cout << "ScavTrap " << _name << " got " << amount << " points of health back!" << std::endl;
        _energyPoint -= 1;
        _hitPoint += amount;
    }
    else if (_hitPoint <= 0)
        std::cout << "ScavTrap " << _name << " is dead :(" << std::endl;
    else if (_energyPoint <= 0)
        std::cout << "ScavTrap " << _name << " is out of energy :(" << std::endl;
}

void ScavTrap::guardGate() {
    if (_energyPoint > 0 && _hitPoint > 0)
    {
        std::cout << "ScavTrap " << _name << " is now in Gate keeper mode!" << std::endl;
        _energyPoint -= 1;
    }
    else if (_hitPoint <= 0)
        std::cout << "ScavTrap " << _name << " is dead :(" << std::endl;
    else if (_energyPoint <= 0)
        std::cout << "ScavTrap " << _name << " is out of energy :(" << std::endl;
}
