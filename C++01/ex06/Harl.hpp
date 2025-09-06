#ifndef HARL_HPP
# define HARL_HPP
# include <string>

class Harl {
    private:
        void debug(void) const;
        void info(void) const;
        void warning(void) const;
        void error(void) const;
        Harl(const Harl& other);
        Harl& operator=(const Harl& rhs);

    public:
        Harl();
        ~Harl();
        void complain(const std::string& level) const;
};

#endif
