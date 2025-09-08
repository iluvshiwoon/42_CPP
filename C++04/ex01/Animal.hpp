#ifndef ANIMAL_HPP
# define ANIMAL_HPP
# include <string>

class Animal {
    protected:
        std::string _type;
    public:
        Animal();
        Animal(const std::string& type);
        Animal(const Animal& other);
        Animal& operator=(const Animal& rhs);
        virtual ~Animal();
        virtual void makeSound() const;
        std::string getType() const;
};

#endif // !ANIMAL_HPP
