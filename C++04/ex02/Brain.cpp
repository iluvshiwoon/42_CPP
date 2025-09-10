#include "Brain.hpp"
#include <iostream>
#include <string>

Brain::Brain() {
    std::cout << "Default Brain constructor called" << std::endl;
}

Brain::Brain(const std::string& idea) {
    for(int i = 0; i < 100; i++)
        _ideas[i] = idea;
    std::cout << "Brain string constructor called" << std::endl;
}

Brain::Brain(const Brain& other) {
    for (int i = 0; i < 100; i++) {
        this->_ideas[i] = other._ideas[i];
    }
    std::cout << "Default Brain copy constructor called" << std::endl;
}

Brain& Brain::operator=(const Brain& rhs) {
    if (this != &rhs) {
        for (int i = 0; i < 100; i++) {
            this->_ideas[i] = rhs._ideas[i];
        }
    }
    std::cout << "Default Brain copy assignment called" << std::endl;
    return *this;
}

Brain::~Brain() {
    std::cout << "Default Brain destructor called" << std::endl;
};
