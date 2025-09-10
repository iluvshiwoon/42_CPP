#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include <iostream>

void testArrayBounds() {
    std::cout << "\n=== Testing Array Bounds Safety ===" << std::endl;
    
    Character hero("Hero");
    MateriaSource source;
    
    std::cout << "\n--- Test 1: Filling inventory ---" << std::endl;
    source.learnMateria(new Ice());
    source.learnMateria(new Cure());
    
    for (int i = 0; i < 6; i++) {  // Try to equip 6 items (more than 4)
        AMateria* mat = source.createMateria("ice");
        if (mat) {
            std::cout << "Attempting to equip item " << (i+1) << std::endl;
            hero.equip(mat);
        }
    }
    
    std::cout << "\n--- Test 2: Invalid array indices ---" << std::endl;
    hero.use(-1, hero);      // Negative index
    hero.use(4, hero);       // Index too high
    hero.use(100, hero);     // Way too high
    
    hero.unequip(-1);        // Negative index
    hero.unequip(4);         // Index too high
    hero.unequip(100);       // Way too high
    
    std::cout << "\n--- Test 3: Filling MateriaSource memory ---" << std::endl;
    MateriaSource fullSource;
    for (int i = 0; i < 6; i++) {  // Try to learn 6 materials (more than 4)
        std::cout << "Attempting to learn materia " << (i+1) << std::endl;
        if (i % 2 == 0)
            fullSource.learnMateria(new Ice());
        else
            fullSource.learnMateria(new Cure());
    }
    
    std::cout << "\n=== All tests completed ===" << std::endl;
}

int main()
{
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    ICharacter* me = new Character("me");
    AMateria* tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);
    ICharacter* bob = new Character("bob");
    me->use(0, *bob);
    me->use(1, *bob);


    delete bob;
    delete me;

    Character one("one");
    one.equip(src->createMateria("ice"));
    Character two(one);
    two.use(0, one);
    two.unequip(0);
    two.use(0, one);
    one.use(0, two);


    delete src;
    testArrayBounds();
    return 0;
}
