#ifndef HUMAN_A_HPP
# define HUMAN_A_HPP
# include "Weapon.hpp"

class HumanA {
    private:
        Weapon& _weapon;
        std::string _name;
    public:
        HumanA(const std::string& name,Weapon& weapon);
        HumanA(const HumanA& other);
        HumanA& operator=(const HumanA& rhs);
        ~HumanA();

        void setWeapon(const Weapon& weapon);
        Weapon getWeapon() const;

        void setName(const std::string& name);
        std::string getName() const;
        void attack() const;
};

#endif // !HUMAN_A_HPP
