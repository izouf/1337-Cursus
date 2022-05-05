#include <iostream>

class Entity
{
private:

public:
    float   X, Y;

    void    Move(float xa, float ya)
    { 
        X += xa;
        Y += ya;  
    }
};

class Player : public Entity 
{
private:

public:
    const char *name;
    
    void    PrintName()
    {
        std::cout << name << std::endl;
    }   
};
 
int main()
{
    Player player1;

    std::cout << sizeof(Entity) << std::endl; 
    std::cout << sizeof(Player) << std::endl;
    player1.Move(5, 4);
    player1.X = 4;
    player1.Y = 2; 
    return (0);
}