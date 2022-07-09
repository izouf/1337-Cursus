#include "span.hpp"

int main()
{
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
    std::cout << std::endl << "---------------------------------------------------------------" << std::endl << std::endl;
	{
        try
        {
           std::vector<int> v;
        
            for (int i = 0; i < 4; i++)
		        v.push_back(i);

            std::vector<int>::iterator begin = v.begin();
            std::vector<int>::iterator end = v.end();
            Span a = Span(5);
            a.addNumber(6);
            a.addNumber(begin, end);
            a.addNumber(3);
            // a.addNumber(17);
            // a.addNumber(9);
            // a.addNumber(11);
            std::cout << "shortest span is " << a.shortestSpan() << std::endl;
            std::cout << "longest span is " << a.longestSpan() << std::endl << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << std::endl;
        }
        
        
	}
    return 0;
}