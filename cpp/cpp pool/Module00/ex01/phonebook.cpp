#include "phonebook.hpp"

int     PhoneBook::totalContact() const 
{
    return (maxIndex);
}

void    PhoneBook::displayContact(const int i) const
{
    Contact     info;

    if (i > totalContact())
        std::cout << "Contact not found !" << std::endl;
    else
    {
        info = contact[i - 1];
        std::cout << "First Name      :\t" << info.getFirstName() << std::endl;
        std::cout << "Last Name       :\t" << info.getLastName() << std::endl;
        std::cout << "Nick Name       :\t" << info.getNickName() << std::endl;
        std::cout << "Phone Number    :\t" << info.getPhoneNumber() << std::endl;
        std::cout << "Darkest Secret  :\t" << info.getDarkestSecret() << std::endl;
    }
}

int PhoneBook::search(void)
{
    int     i;

    std::cout << std::endl;
    if (!totalContact())
    {
        std::cout << "Empty PhoneBook please Add Contact first !" << std::endl;
        return (0);
    }
    std::cout << "|----------------------------------------|" << std::endl;
    std::cout << "|  Index|First Name| Last Name| Nick Name|" << std::endl;
    std::cout << "|----------------------------------------|" << std::endl;
    for (int j = 0; j < totalContact(); j++)
    {
        std::cout   << "|" << std::setw(7) << j + 1 << "|";
        if (contact[j].getFirstName().length() > 10)
            std::cout << contact[j].getFirstName().substr(0, 9) << "." << "|";
        else
            std::cout << std::setw(10) << contact[j].getFirstName() << "|";
        if (contact[j].getLastName().length() > 10)
            std::cout << contact[j].getLastName().substr(0, 9) << "."  << "|";
        else
            std::cout << std::setw(10) << contact[j].getLastName() << "|";
        if (contact[j].getNickName().length() > 10)
            std::cout << contact[j].getNickName().substr(0, 9) << "."  << "|";
        else
            std::cout << std::setw(10) << contact[j].getNickName() << "|";
        std::cout << std::endl << "|----------------------------------------|" << std::endl;
    }
    std::cin >> i;
    if (i <= 0 || i > 8)
        std::cout << "Wrong Index";
    else
        displayContact(i);
    return (0);
}

int PhoneBook::add(void)
{
    int         i;
    int         j;
    std::string str;

    if (this->maxIndex >= 8)
        this->maxIndex = 7;
    if (this->contactIndex == 8)
        this->contactIndex = 0;
    i = contactIndex++;
    j = maxIndex++;
    std::cout << std::endl;
    std::cout << " First Name     :\t";
    std::cin >> str;
    contact[i].setFirstName(str);
    std::cout << " Last Name      :\t";
    std::cin >> str;
    contact[i].setLastName(str);
    std::cout << " Nick Name      :\t";
    std::cin >> str;
    contact[i].setNickName(str);
    std::cout << " Phone Number   :\t";
    std::cin >> str;
    contact[i].setPhoneNumber(str);
    std::cout << " Darkest Secret :\t";
    std::cin >> str;
    contact[i].setDarkestSecret(str);
    return (1);
}