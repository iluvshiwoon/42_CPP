#include "HumanB.hpp"
#include "Weapon.hpp"
#include <iostream>

HumanB::HumanB(const std::string& name) :
    _weapon(NULL),
    _name(name) {
}

HumanB::HumanB(const HumanB& other) :
    _weapon(other._weapon),
    _name(other._name) {
}

HumanB& HumanB::operator=(const HumanB& rhs) {
    if (this != &rhs)
    {
        _weapon = rhs._weapon;
        _name = rhs._name;
    }
    return *this;
}

HumanB::~HumanB(){};

void HumanB::attack() const {
    if (_weapon)
        std::cout << _name << " attacks with their " << _weapon->getType() << std::endl;
    else
        std::cout << _name << " attacks with their bare hands" << std::endl;
}

void HumanB::setWeapon(Weapon& weapon) {
    _weapon = &weapon;
}

Weapon HumanB::getWeapon() const {
    return *_weapon;
}

void HumanB::setName(const std::string& name) {
    _name = name;
}
std::string HumanB::getName() const {
    return _name;
}

