#include "MateriaSource.hpp"
#include "AMateria.hpp"
#include <iostream>

MateriaSource::MateriaSource() : _memory() {
    std::cout << "Default MateriaSource constructor called" << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource& other) : _memory() {
    for (int i = 0; i < 4; i++) {
        if (other._memory[i] != NULL)
            this->_memory[i] = other._memory[i]->clone();
    }
    std::cout << "Default MateriaSource copy constructor called" << std::endl;
}

MateriaSource& MateriaSource::operator=(const MateriaSource& rhs) {
    if (this != &rhs) {
        for (int i = 0; i < 4; i++) {
            delete this->_memory[i];
            if (rhs._memory[i] != NULL)
                this->_memory[i] = rhs._memory[i]->clone();
            else
                this->_memory[i] = NULL;
        }
        std::cout << "MateriaSource assigment operator called" << std::endl;
    }
    return *this;
}

MateriaSource::~MateriaSource() {
    for (int i = 0; i < 4; i++) {
        delete this->_memory[i];
    }
    std::cout << "Default MateriaSource destructor called" << std::endl;
}

void MateriaSource::learnMateria(AMateria* m) {
    for (int i = 0; i < 4; i++) {
        if (this->_memory[i] == NULL) {
            this->_memory[i] = m;
            std::cout << "MateriaSource learned a Materia" << std::endl;
            break;
        }
    }
}

AMateria* MateriaSource::createMateria(const std::string& type) {
    for (int i = 0; i < 4; i++) {
        if (this->_memory[i] != NULL && this->_memory[i]->getType() == type) {
            std::cout << "MateriaSource created a Materia" << std::endl;
            return this->_memory[i]->clone();
        }
    }
    return NULL;
}
