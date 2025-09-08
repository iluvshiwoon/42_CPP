#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP
# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
    public:
        ScavTrap();
        ScavTrap(const std::string name);
        ScavTrap(const ScavTrap& other);
        ScavTrap& operator=(const ScavTrap& rhs);
        ~ScavTrap();

        void guardGate();
        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);

};

#endif // !SCAVTRAP_HPP
