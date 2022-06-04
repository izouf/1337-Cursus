#include "MutantStack.hpp"

int main()
{
    MutantStack<std::string> mStringStack;
    mStringStack.push("Lhaj");
    mStringStack.push("Houssam");
    mStringStack.pop();
    mStringStack.push("Houssam");

    MutantStack<int> mIntStack;
    mIntStack.push(42);
    mIntStack.push(1337);
    mIntStack.pop();
    mIntStack.push(1337);

    MutantStack<std::string>::iterator sbegin = mStringStack.begin();
    MutantStack<std::string>::iterator send = mStringStack.end();

    sbegin++;
    send--;
    std::cout << "String Iterator : ";
    while(sbegin != send)
    {
        std::cout << *sbegin << ", ";
        sbegin++;
    }
    std::cout << std::endl << "*** String Stack Infos ***" << std::endl;
    std::cout << mStringStack.size() << std::endl << "Empty : " << (mStringStack.empty() ? "true\n" : "false\n");
    mStringStack.pop();
    mStringStack.pop();
    std::cout << mStringStack.size() << std::endl << "Empty : " << (mStringStack.empty() ? "true\n" : "false\n");
    std::cout << "-----------------------------------------------" << std::endl;

    MutantStack<int>::iterator ibegin = mIntStack.begin();
    MutantStack<int>::iterator iend = mIntStack.end();

    ibegin++;
    iend--;
    std::cout << "Int Iterator : ";
    while(ibegin != iend)
    {
        std::cout << *ibegin << ", ";
        ibegin++;
    }
    std::cout << std::endl << "***Int Stack Infos ***" << std::endl;
    std::cout << mIntStack.size() << std::endl << "Empty : " << (mIntStack.empty() ? "true\n" : "false\n");
    mIntStack.pop();
    mIntStack.pop();
    std::cout << mIntStack.size() << std::endl << "Empty : " << (mIntStack.empty() ? "true\n" : "false\n");
    return (0);
}