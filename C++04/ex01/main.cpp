#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include <iostream>

int main() {
    Animal * park[10];

    for (int i = 0; i < 5; i++) {
        park[i] = new Dog();
        park[i]->makeSound();
    }
    for (int i = 5; i < 10; i++) {
        park[i] = new Cat();
        park[i]->makeSound();
    }
    for (int i = 0; i < 10; i++)
        delete park[i];

    Cat a;
    Cat b;
    std::cout << "a's brain address: " << a.getAddress() << std::endl;
    std::cout << "b's brain address: " << b.getAddress() << std::endl;
    a = b;
    std::cout << "b's brain address: " << b.getAddress() << std::endl;
    std::cout << "a's brain address after copy: " << a.getAddress() << std::endl;

    return 0;
}
