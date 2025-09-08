#include "FragTrap.hpp"
#include "ClapTrap.hpp"

int main()
{
    ClapTrap robot("C-32");
    FragTrap Alien("Xaak");

    robot.attack("Xaak");
    Alien.takeDamage(0);
    Alien.attack("C-32");
    robot.takeDamage(20);
    robot.attack("nothing");
    robot.beRepaired(5);
    Alien.beRepaired(0);

    Alien.highFiveGuys();
    for (int i = 0; i < 101; i++)
        Alien.attack("absolutly nothing");
    Alien.takeDamage(100);
    Alien.attack("absolutly nothing");
    return 0;
}
