#include <iostream>
#include <memory>

class Entity
{
public:
    Entity()
    {
        std::cout << "Created Entity!" << std::endl;
    } 
    ~Entity()
    {
        std::cout << "Destroyed Entity !"<< std::endl;
    }
    void Print()
    {
    
    }
};



int main()
{
    {
        std::unique_ptr<Entity>entity(new Entity());
        entity->Print();
    }
    return (0);
}