#include "Character.hpp"
#include "AMateria.hpp"
#include "linklist.h"
#include <iostream>
#include <string>

Character::Character() : _inventory(), _trashHead(NULL) {
    std::cout << "Default Character constructor called" << std::endl;
}

Character::Character(const std::string& name) : _name(name), _inventory(), _trashHead(NULL) {
    std::cout << "Default Character string constructor called" << std::endl;
}

Character::Character(const Character& other) : _name(other._name), _trashHead(other._trashHead) {
    for (int i = 0; i < 4; i++)
        _inventory[i] = other._inventory[i]->clone();
    std::cout << "Default Character copy constructor called" << std::endl;
}

Character& Character::operator=(const Character& rhs) {
    if (this != &rhs) {
        this->_name = rhs._name;
        while(this->_trashHead) {
            node* temp = this->_trashHead;
            this->_trashHead = this->_trashHead->next;
            delete temp;
        }
        this->_trashHead = rhs._trashHead;
        for (int i = 0; i < 4; i++)
        {
            delete this->_inventory[i];
            this->_inventory[i] = rhs._inventory[i]->clone();
        }
    }
    std::cout << "Default Character copy assignment called" << std::endl;
    return *this;
}

Character::~Character() {
    while(this->_trashHead) {
            node* temp = this->_trashHead;
            this->_trashHead = this->_trashHead->next;
            delete temp;
    }
    for (int i = 0; i < 4; i++) {
            delete this->_inventory[i];
    }
    std::cout << "Default Character destructor called" << std::endl;
};

const std::string& Character::getName() const {
    return _name;
}

void Character::equip(AMateria* m) {
    for (int i = 0; i < 4; i++) {
        if (_inventory[i] == NULL) {
            _inventory[i] = m;
            break;
            std::cout << "Character equip called" << std::endl;
        }
    }
}
void Character::unequip(int idx) { if (_inventory[idx] != NULL) { node* n = new node(); 
        n->material = _inventory[idx];
        n->next = _trashHead;
        _trashHead = n;
        _inventory[idx] = NULL;
        std::cout << "Character unequip called" << std::endl;
    }
}

void Character::use(int idx, ICharacter& target) {
    if (_inventory[idx] != NULL) {
        _inventory[idx]->use(target);
        std::cout << "Character use called" << std::endl;
    }
}
