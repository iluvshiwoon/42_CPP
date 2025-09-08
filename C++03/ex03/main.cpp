#include "DiamondTrap.hpp"

int main()
{
    ClapTrap robot("C-32");
    DiamondTrap Alien("Xaak");
    DiamondTrap Alien1(Alien);

    Alien.WhoAmI();
    Alien1.WhoAmI();
    DiamondTrap Alien2 = Alien1;
    Alien2.WhoAmI();
    robot.attack("Xaak");
    Alien.takeDamage(0);
    Alien.attack("C-32");
    robot.takeDamage(20);
    robot.attack("nothing");
    robot.beRepaired(5);
    Alien.beRepaired(0);

    for (int i = 0; i < 51; i++)
        Alien.attack("absolutly nothing");
    Alien.takeDamage(100);
    Alien.attack("absolutly nothing");
    return 0;
}
