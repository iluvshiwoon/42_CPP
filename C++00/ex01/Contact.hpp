#ifndef CONTACT_HPP
# define CONTACT_HPP
# include <string>

class Contact {
    private:
        std::string _firstName; 
        std::string _lastName; 
        std::string _nickName; 
        std::string _phoneNumber; 
        std::string _darkestSecret; 

    public:
        Contact();
        Contact(const Contact &other);
        Contact& operator=(const Contact &rhs);
        ~Contact();

        bool setFirstName(std::string& firstName);
        bool setLastName(std::string& lastName);
        bool setNickName(std::string& nickName);
        bool setPhoneNumber(std::string& phoneNumber);
        bool setDarkestSecret(std::string& darkestSecret);

        std::string getFirstName() const;
        std::string getLastName() const;
        std::string getNickName() const;
        std::string getPhoneNumber() const;
        std::string getDarkestSecret() const;

        std::string formatField(std::string field) const;
        void displayContact() const;
};

#endif
