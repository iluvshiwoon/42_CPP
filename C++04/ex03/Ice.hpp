#ifndef Ice_HPP
# define Ice_HPP
# include "AMateria.hpp"

class Ice : public AMateria {
    public:
        Ice();
        Ice(const Ice& other);
        Ice& operator=(const Ice& rhs);
        ~Ice();
        Ice* clone() const;
        // void use(Icharacter& target);
};

#endif // !Ice_HPP
