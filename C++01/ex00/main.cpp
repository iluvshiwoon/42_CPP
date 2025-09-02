#include "Zombie.hpp"
#include <new>
#include <iostream>

Zombie* newZombie(std::string name){
    Zombie* zomb = new Zombie(name);

    return zomb;
}

void randomChump(std::string name){
    Zombie chump(name);

    chump.announce();
}

int main(){
    try {
        Zombie* zombie = newZombie("Jean");
        zombie->announce();
        delete zombie;
    } catch (const std::bad_alloc& e) {
        std::cout << "Memory error" << e.what() << std::endl;
    }
 
    randomChump("Mickey");
    return 1;
}
