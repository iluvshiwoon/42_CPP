#ifndef Cure_HPP
# define Cure_HPP
# include "AMateria.hpp"

class Cure : public AMateria {
    public:
        Cure();
        Cure(const Cure& other);
        Cure& operator=(const Cure& rhs);
        ~Cure();
        Cure* clone() const;
};

#endif // !Cure_HPP
