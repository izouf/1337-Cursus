#include <iostream>

class   Player
{
    public:
    
    int     x, y;
    int     moveSpeed;

    void    Move(int xa, int ya)
    {
        x += xa * moveSpeed;
        y += ya * moveSpeed;
    }

};

void    Message(const char *str)
{
    std::cout << str << std::endl;
}

int main(int argc, const char *argv[])
{
    Player  player;
    player.x = 1;
    player.y = 2;
    player.moveSpeed = 3;
    player.Move (5, 3);
    std::cout << player.x << " , " << player.y  << std::endl; 
    return (0);
}