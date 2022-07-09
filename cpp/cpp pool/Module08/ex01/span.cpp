#include "span.hpp"

Span::Span(): size(0), pos(0){}

Span::Span(unsigned int N) : size(N), pos(0)
{
    this->storage.reserve(this->getSize());
}

Span::Span(const Span &copy) : size(copy.getSize())
{
    *this = copy;
}

Span::~Span(){}

Span    &Span::operator=(const Span &src)
{
    if (this != &src)
    {
        this->size = src.size;
        this->storage = src.storage;
        this->pos = src.pos;
    }
    return (*this);
}

void    Span::addNumber(int number)
{
    if (this->storage.size() == this->size)
		throw (Span::FullArrayException());
    this->storage.push_back(number);
    pos++;
}

unsigned int    Span::shortestSpan()const
{
    if (this->storage.size() == 1)
        throw (Span::InvalidComparisonException());
    unsigned int    ret = UINT_MAX;
    std::vector<int> v(this->storage);

    std::sort(v.begin(), v.end());

    std::vector<int>::iterator tempIt = v.begin();
    std::vector<int>::iterator tempNextIt = v.begin() + 1;
    while (tempNextIt != v.end())
    {
        if ((unsigned int)(*tempNextIt - *tempIt) < ret)
            ret = *tempNextIt - *tempIt;
        tempNextIt++;
        tempIt++;    
    }
    return (ret);
}

unsigned int    Span::longestSpan()const
{
    if (this->storage.size() == 1)
        throw (Span::InvalidComparisonException());

    std::vector<int> v(this->storage);

    int min = *min_element(v.begin(), v.end());
    int max = *max_element(v.begin(), v.end());
    return (max - min);
}

unsigned int    Span::getSize() const
{
    return (this->size);
}

void Span::addNumber(std::vector<int>::iterator const &begin, std::vector<int>::iterator const &end)
{
	int d = std::distance(begin, end);

	if (d > static_cast<int>(this->size - this->pos))
		throw Span::FullArrayException();
	storage.insert(storage.end(), begin, end);
    pos += d;
}