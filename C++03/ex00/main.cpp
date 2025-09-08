#include "ClapTrap.hpp"

int main()
{
    ClapTrap robot("C-32");
    ClapTrap Alien("Xaak");

    robot.attack("Xaak");
    Alien.takeDamage(0);
    Alien.attack("C-32");
    robot.takeDamage(0);
    robot.beRepaired(0);
    Alien.beRepaired(0);
    return 0;
}
