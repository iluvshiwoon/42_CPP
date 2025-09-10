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

Character::Character(const Character& other) : _name(other._name), _inventory(), _trashHead(other._trashHead) {
    for (int i = 0; i < 4; i++) {
        if (other._inventory[i] != NULL) 
            this->_inventory[i] = other._inventory[i]->clone();
    }
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
            if (rhs._inventory[i] != NULL) 
                 this->_inventory[i] = rhs._inventory[i]->clone();
            else
                this->_inventory[i] = NULL;
        }
    }
    std::cout << "Default Character copy assignment called" << std::endl;
    return *this;
}

Character::~Character() {
    while(this->_trashHead != NULL) {
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
    return this->_name;
}

void Character::equip(AMateria* m) {
    for (int i = 0; i < 4; i++) {
        if (this->_inventory[i] == NULL) {
            this->_inventory[i] = m;
            break;
            std::cout << "Character equip called" << std::endl;
        }
    }
}

void Character::unequip(int idx) {
    if (_inventory[idx] != NULL) { 
        node* n = new node(); 
        n->material = this->_inventory[idx];
        n->next = _trashHead;
        this->_trashHead = n;
        this->_inventory[idx] = NULL;
        std::cout << "Character unequip called" << std::endl;
    }
}

void Character::use(int idx, ICharacter& target) {
    if (this->_inventory[idx] != NULL) {
        this->_inventory[idx]->use(target);
        std::cout << "Character use called" << std::endl;
    }
}
