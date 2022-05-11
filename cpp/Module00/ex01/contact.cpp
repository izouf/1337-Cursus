#include "contact.hpp"

void    Contact::setFirstName(const std::string str){firstName = str;}
void    Contact::setLastName(const std::string str){lastName = str;}
void    Contact::setNickName(const std::string str){nickName = str;}
void    Contact::setPhoneNumber(const std::string str){phoneNumber = str;}
void    Contact::setDarkestSecret(const std::string str){darkestSecret = str;}

std::string Contact::getFirstName() const {return (firstName);}
std::string Contact::getLastName() const {return (lastName);}
std::string Contact::getNickName() const {return (nickName);}
std::string Contact::getPhoneNumber() const {return (phoneNumber);}
std::string Contact::getDarkestSecret() const {return (darkestSecret);}