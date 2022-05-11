void PhoneBook::PrintDetailContact(const int i) const
{
    Info info = contact[i - 1];

    std::cout << std::endl;
    std::cout << "-------------------------------------------" << std::endl;
    std::cout << "First Name : " << info.getFirstName() << std::endl;
    std::cout << "Last Name : " << info.getLastName() << std::endl;
    std::cout << "Nickname : " << info.getNickname() << std::endl;
    std::cout << "Login : " << info.getLogin() << std::endl;
    std::cout << "Postal Address : " << info.getPostalAddress() << std::endl;
    std::cout << "Email Address : " << info.getEmailAddress() << std::endl;
    std::cout << "Phone Number : " << info.getPhoneNumber() << std::endl;
    std::cout << "Birthday Date : " << info.getBirthdayDate() << std::endl;
    std::cout << "Favorite Meal : " << info.getFavoriteMeal() << std::endl;
    std::cout << "Underwear Color : " << info.getUnderwearColor() << std::endl;
    std::cout << "Darkest Secret : " << info.getDarkestSecret() << std::endl;
    std::cout << "-------------------------------------------" << std::endl;
}