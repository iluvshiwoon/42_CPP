#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

class PhoneBook {
    private:
        Contact _contacts[8];
        int _count;
        int _nextIndex;

    public:
        PhoneBook();
        PhoneBook(const PhoneBook& other);
        PhoneBook& operator=(const PhoneBook& rhs);
        ~PhoneBook();

        bool isValid(int& index) const;
        void addContact(Contact& contact);
        void displayContacts() const;
        void displayContact(const int& index) const;
};
#endif
