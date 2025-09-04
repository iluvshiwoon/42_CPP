#include "Weapon.hpp"

Weapon::Weapon(){}

Weapon::Weapon(const std::string& type) : 
    _type(type) {

}

Weapon::Weapon(const Weapon& other) :
    _type(other._type) {
}

Weapon::~Weapon() {}

Weapon& Weapon::operator=(const Weapon& rhs) {
    if (this != &rhs) {
        _type = rhs._type;
    }
    return *this;
}

std::string Weapon::getType() const {
    return _type;
}

void Weapon::setType(const std::string& type) {
    _type = type;
}
