#include "HumanA.hpp"
#include "Weapon.hpp"
#include <iostream>

HumanA::HumanA(const std::string& name, Weapon& Weapon) :
    _weapon(Weapon),
    _name(name) {
}

HumanA::HumanA(const HumanA& other) :
    _weapon(other._weapon),
    _name(other._name) {
}

HumanA& HumanA::operator=(const HumanA& rhs) {
    if (this != &rhs)
    {
        _weapon = rhs._weapon;
        _name = rhs._name;
    }
    return *this;
}

HumanA::~HumanA(){};

void HumanA::attack() const {
    std::cout << _name << " attacks with their " << _weapon.getType() << std::endl;
}

void HumanA::setWeapon(const Weapon& weapon) {
    _weapon = weapon;
}

Weapon HumanA::getWeapon() const {
    return _weapon;
}

void HumanA::setName(const std::string& name) {
    _name = name;
}
std::string HumanA::getName() const {
    return _name;
}

