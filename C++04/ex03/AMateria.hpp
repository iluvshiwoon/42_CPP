#ifndef AMATERIA_HPP
# define AMATERIA_HPP
# include <string>

class AMateria {
    protected:
        std::string _type;
    public:
        AMateria();
        AMateria(const std::string& type);
        AMateria(const AMateria& other);
        AMateria& operator=(const AMateria& rhs);
        virtual ~AMateria();
        virtual AMateria* clone() const = 0;
        // virtual void use(Icharacter& target);
        std::string getType() const;
};

#endif // !AMATERIA_HPP
