#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <iostream>
#include <ostream>
#include <string>

void addContact(PhoneBook& phonebook)
{
    Contact contact;
    std::string line;

    do {
        std::cout << std::endl;
        std::cout << "first name: ";
        std::getline(std::cin,line);
    } while (contact.setFirstName(line) == false);
    do {
        std::cout << std::endl;
        std::cout << "last name: ";
        std::getline(std::cin,line);
    } while (contact.setLastName(line) == false);
    do {
        std::cout << std::endl;
        std::cout << "nickname: ";
        std::getline(std::cin,line);
    } while (contact.setNickName(line) == false);
    do {
        std::cout << std::endl;
        std::cout << "phone number: ";
        std::getline(std::cin,line);
    } while (contact.setPhoneNumber(line) == false);
    do {
        std::cout << std::endl;
        std::cout << "darkest secret: ";
        std::getline(std::cin,line);
    } while (contact.setDarkestSecret(line) == false);
    phonebook.addContact(contact);
}

int main()
{
    std::cout << "Welcome, type ADD to add a new contact, \
SEARCH to display a specific contact or EXIT to quit" << std::endl;
    std::string line;
    PhoneBook phonebook;
    while(1)
    {
        std::getline(std::cin,line);
        if (line == "ADD")
            addContact(phonebook);
        else if (line == "SEARCH")
        {
            std::cout << std::endl;
            phonebook.displayContacts();
            std::cout << std::endl << "Enter index: ";
            getline(std::cin, line); 
            int index = line[0] - '0';
            if (line.length() == 1 && index >= 0 && index <= 7 && phonebook.isValid(index))
            {
                std::cout << std::endl;
                phonebook.displayContact(index);
            }
            else 
                std::cout << "Invalid" << std::endl;
        }
        else if (line == "EXIT")
            return 1;
    }
}
