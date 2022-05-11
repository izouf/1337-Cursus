#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "contact.hpp"
class   PhoneBook
{
private:
    int     contactIndex;
    int     maxIndex;
    Contact contact[8];
public:
    PhoneBook() : contactIndex(0){};
    ~PhoneBook(){};
    int     add(void);
    int     totalContact() const;
    void    displayContact(const int i) const;
    int     search(void);
};
#endif