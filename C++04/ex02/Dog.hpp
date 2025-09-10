#ifndef DOG_HPP
# define DOG_HPP
# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal {
    private:
        Brain* _brain; 
    public:
        Dog();
        Dog(const Dog& other);
        Dog& operator=(const Dog& rhs);
        ~Dog();
        void makeSound() const;
        const Brain* getAddress() const;
};

#endif // !DOG_HPP
