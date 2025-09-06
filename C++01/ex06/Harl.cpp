#include "Harl.hpp"
#include <iostream>
#include <ostream>

Harl::Harl(){};
Harl::~Harl(){};
Harl::Harl(const Harl& other){
    (void)other;
}
Harl& Harl::operator=(const Harl& rhs){
    (void)rhs;
    return *this;
}
void Harl::debug() const{
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup \
burger. I really do!" << std::endl;
}

void Harl::info() const{
    std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put \
enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning() const{
    std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for \
years whereas you started working here since last month." << std::endl;
}

void Harl::error() const{
    std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complain(const std::string& level) const{
    std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

    int levelIndex = -1;
    for (int i = 0; i < 4; i++) {
        if (levels[i] == level)
            levelIndex = i;
    }

    switch (levelIndex) {
        case 0 :
            std::cout << "[ DEBUG ]" << std::endl;
            debug();
        case 1 :
            if (levelIndex <= 0) std::cout << std::endl;
            std::cout << "[ INFO ]" << std::endl;
            info();
        case 2 :
            if (levelIndex <= 1) std::cout << std::endl;
            std::cout << "[ WARNING ]" << std::endl;
            warning();
        case 3 :
            if (levelIndex <= 2) std::cout << std::endl;
            std::cout << "[ ERROR ]" << std::endl;
            error();
            break;
        default : 
            std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
            break;
    }
}
