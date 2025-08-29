#include "PhoneBook.hpp"
#include <iostream>
#include <string>

PhoneBook::PhoneBook() : 
    _count(0),
    _nextIndex(0)
{
}

PhoneBook::PhoneBook(const PhoneBook& other) :
    _count(other._count),
    _nextIndex(other._nextIndex)
{
    for (int i = 0; i < 8; i++) 
        _contacts[i] = other._contacts[i];
}

PhoneBook& PhoneBook::operator=(const PhoneBook& rhs){
    if (this != &rhs)
    {
        _count = rhs._count;
        _nextIndex = rhs._nextIndex;
        for (int i = 0; i < 8; i++)
            _contacts[i] = rhs._contacts[i];
    }
    return *this;
}

PhoneBook::~PhoneBook() {
}

bool PhoneBook::isValid(int& index) const {
    return index < _count; 
}

void PhoneBook::addContact(Contact& contact) {
    _contacts[_nextIndex] = contact;
    _nextIndex = (_nextIndex + 1) % 8;
    if (_count < 8)
        _count += 1;
}

void PhoneBook::displayContacts() const {
    Contact temp;
    std::cout << temp.formatField("index") << "|" << temp.formatField("first name") \
        << "|" << temp.formatField("last name") << "|" << temp.formatField("nickname") \
        << std::endl;
    for (int i = 0; i < _count; i++)
    {
        std::cout << temp.formatField(std::to_string(i)) << "|" \
            << temp.formatField(_contacts[i].getFirstName()) << "|" \
            << temp.formatField(_contacts[i].getLastName()) << "|" \
            << temp.formatField(_contacts[i].getNickName()) << std::endl;
    }
}

void PhoneBook::displayContact(const int& index) const
{
    _contacts[index].displayContact();
}
