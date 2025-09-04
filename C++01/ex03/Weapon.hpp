#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <string>

class Weapon {
    private:
        std::string _type;
    public:
        Weapon();
        Weapon(const std::string& type);
        Weapon(const Weapon& other);
        Weapon& operator=(const Weapon& rhs);
        ~Weapon();

        std::string getType() const;
        void setType(const std::string& type);
};
#endif
