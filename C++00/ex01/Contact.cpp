#include "Contact.hpp"
#include <iostream>

using std::string;

Contact::Contact() {}

Contact::Contact(const Contact& other) :
    _firstName(other._firstName),
    _lastName(other._lastName),
    _nickName(other._nickName),
    _darkestSecret(other._darkestSecret)
{
}

Contact& Contact::operator=(const Contact& rhs)
{
    if (this != &rhs)
    {
        _firstName = rhs._firstName;
        _lastName = rhs._lastName;
        _nickName = rhs._nickName;
        _phoneNumber = rhs._phoneNumber;
        _darkestSecret = rhs._darkestSecret;
    }
    return *this;
}

Contact::~Contact(){
}

bool Contact::setFirstName(std::string &firstName)
{
    if (firstName.empty() == true)
        return false;
    _firstName = firstName;
    return true;
}

bool Contact::setLastName(std::string &lastName)
{
    if (lastName.empty() == true)
        return false;
    _lastName = lastName;
    return true;
}

bool Contact::setNickName(std::string &nickName)
{
    if (nickName.empty() == true)
        return false;
    _nickName = nickName;
    return true;
}

bool Contact::setPhoneNumber(std::string &phoneNumber)
{
    if (phoneNumber.empty() == true)
        return false;
    _phoneNumber = phoneNumber;
    return true;
}

bool Contact::setDarkestSecret(std::string &darkestSecret)
{
    if (darkestSecret.empty() == true)
        return false;
    _darkestSecret = darkestSecret;
    return true;
}

std::string Contact::getFirstName() const {
    return _firstName;
}

std::string Contact::getLastName() const {
    return _lastName;
}

std::string Contact::getNickName() const {
    return _nickName;
}

std::string Contact::getPhoneNumber() const {
    return _phoneNumber;
}

std::string Contact::getDarkestSecret() const {
    return _darkestSecret;
}

void Contact::displayContact() const {
    std::cout << "First Name     : " << _firstName << std::endl;
    std::cout << "Last Name      : " << _lastName << std::endl;
    std::cout << "Nick Name      : " << _nickName << std::endl;
    std::cout << "Phone Number   : " << _phoneNumber << std::endl;
    std::cout << "Darkest Secret : " << _darkestSecret << std::endl;
}

std::string Contact::formatField(std::string field) const {
    while (field.length() < 10) 
        field = " " + field;
    if (field.length() > 10)
        field = field.substr(0, 9) + ".";
    return field;
}
