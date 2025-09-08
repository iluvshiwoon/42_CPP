#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include <iostream>

int main() {
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    delete j;
    delete i;

    Dog k;
    Dog l(k);

    k = l;
    return 0;
}
