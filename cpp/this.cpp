#include <iostream>
#include <string>

class   Entity
{
public:
    int x, y;

    Entity(int x, int y)
    {
       /* Entity *e = this;
        e->x = x;*/
        this->x = x;
        this->y - y;
    }
    int GetX() const
    {
        return x;
    }
};

int main()
{
    return (0);
}