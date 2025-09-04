#ifndef HUMAN_B_HPP
# define HUMAN_B_HPP
# include "Weapon.hpp"

class HumanB {
    private:
        Weapon* _weapon;
        std::string _name;
    public:
        HumanB(const std::string& name);
        HumanB(const HumanB& other);
        HumanB& operator=(const HumanB& rhs);
        ~HumanB();

        void attack() const;
        void setWeapon(Weapon& weapon);
        Weapon getWeapon() const;

        void setName(const std::string& name);
        std::string getName() const;

};

#endif // !HUMAN_B_HPP
