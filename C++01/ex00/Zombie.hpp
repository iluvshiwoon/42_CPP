#ifndef ZOMBIE_H
# define ZOMBIE_H
# include <string>

class Zombie {
    private:
        std::string _name;
    public:
        Zombie(const std::string& name);
        Zombie(const Zombie& other);
        Zombie& operator=(const Zombie& rhs);
        ~Zombie();

        void setName(const std::string& name);
        std::string getName() const;
        void announce(void) const;
};

#endif
