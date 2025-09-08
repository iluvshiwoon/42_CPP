#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "DiamondTrap.hpp"
#include <iostream>
#include <string>

DiamondTrap::DiamondTrap() :
    ClapTrap(), ScavTrap(), FragTrap() {
    this->_energyPoint = 50;

    std::cout << "DiamondTrap default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const std::string name) : 
    ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name), _name(name) {
    this->_energyPoint = 50;

    std::cout << "DiamondTrap constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other) :
    ClapTrap(other._name + "_clap_name"), ScavTrap(), FragTrap(){
    this->_name = other._name;

    std::cout << "DiamondTrap copy constructor called" << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& rhs) {
    if (this != &rhs)
    {
        _name = rhs._name;
        _hitPoint = rhs._hitPoint;
        _energyPoint = rhs._energyPoint;
        _attackDamage = rhs._attackDamage;
    }
    std::cout << "DiamondTrap operator = called" << std::endl;
    return *this;
}

DiamondTrap::~DiamondTrap() { std::cout << "DiamondTrap destructor called" << std::endl; }

void DiamondTrap::attack(const std::string& target) {
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

void DiamondTrap::takeDamage(unsigned int amount) {
    if (_hitPoint > 0)
    {
        std::cout << "DiamondTrap " << _name << " took " << amount << " points of damage!" << std::endl;
        _hitPoint -= amount;
    }
    else if (_hitPoint <= 0)
        std::cout << "DiamondTrap " << _name << " is dead :(" << std::endl;
}

void DiamondTrap::beRepaired(unsigned int amount) {
    if (_energyPoint > 0 && _hitPoint > 0)
    {
        std::cout << "DiamondTrap " << _name << " got " << amount << " points of health back!" << std::endl;
        _energyPoint -= 1;
        _hitPoint += amount;
    }
    else if (_hitPoint <= 0)
        std::cout << "DiamondTrap " << _name << " is dead :(" << std::endl;
    else if (_energyPoint <= 0)
        std::cout << "DiamondTrap " << _name << " is out of energy :(" << std::endl;
}

void DiamondTrap::WhoAmI() {
    if (_energyPoint > 0 && _hitPoint > 0)
    {
        std::cout << "DiamondTrap name: " << _name << " ClapTrap name: " << ClapTrap::_name << std::endl;
        _energyPoint -= 1;
    }
    else if (_hitPoint <= 0)
        std::cout << "DiamondTrap " << _name << " is dead :(" << std::endl;
    else if (_energyPoint <= 0)
        std::cout << "DiamondTrap " << _name << " is out of energy :(" << std::endl;
}
