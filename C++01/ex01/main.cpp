#include "Zombie.hpp"
#include "Zombie.h"
#include <new>
#include <iostream>
int main(){
    try {
        Zombie* zombie = zombieHorde(8,"Jean");
        for (int i = 0; i < 8; i++)
            zombie[i].announce();
        delete[] zombie;
    } catch (const std::bad_alloc& e) {
        std::cout << "Memory error" << e.what() << std::endl;
    }

    return 1;
}
