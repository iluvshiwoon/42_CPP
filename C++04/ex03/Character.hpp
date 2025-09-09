#ifndef CHARACTER_HPP
# define CHARACTER_HPP
# include <string>
# include "AMateria.hpp"

class ICharacter {
    private:
        AMateria* _inventory[4] = {}; 
        std::string _name;
    public:
        ICharacter();
        ICharacter(const std::string& name);
        ICharacter(const ICharacter& other);
        ICharacter& operator=(const ICharacter& rhs);

        virtual ~ICharacter();
        virtual std::string const & getName() const = 0;
        virtual void equip(AMateria* m) = 0;
        virtual void unequip(int idx) = 0;
        virtual void use(int idx, ICharacter& target) = 0;
};

#endif // !CHARACTER_HPP
