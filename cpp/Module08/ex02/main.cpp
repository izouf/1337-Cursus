#include "MutantStack.hpp"

int main()
{
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

        //ibegin++;
        //iend--;
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
    }
    std::cout << "**********************************************************************" << std::endl;
    std::cout << "**********************************************************************" << std::endl;
    {
        std::vector<std::string> mStringStack;
        mStringStack.push_back("Lhaj");
        mStringStack.push_back("Houssam");
        mStringStack.pop_back();
        mStringStack.push_back("Houssam");

        std::vector<int> mIntStack;
        mIntStack.push_back(42);
        mIntStack.push_back(1337);
        mIntStack.pop_back();
        mIntStack.push_back(1337);

        std::vector<std::string>::iterator sbegin = mStringStack.begin();
        std::vector<std::string>::iterator send = mStringStack.end();

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
        mStringStack.pop_back();
        mStringStack.pop_back();
        std::cout << mStringStack.size() << std::endl << "Empty : " << (mStringStack.empty() ? "true\n" : "false\n");
        std::cout << "-----------------------------------------------" << std::endl;

        std::vector<int>::iterator ibegin = mIntStack.begin();
        std::vector<int>::iterator iend = mIntStack.end();

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
        mIntStack.pop_back();
        mIntStack.pop_back();
        std::cout << mIntStack.size() << std::endl << "Empty : " << (mIntStack.empty() ? "true\n" : "false\n");
    }
    return (0);
}