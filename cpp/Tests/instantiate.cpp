#include <iostream>
#include <string>

class Entity
{
private:
    std::string m_name;
public:
    Entity() : m_name("Unknown"){}
    Entity(const std::string &name) : m_name(name){}

    const std::string &getName()const {return m_name; }
};


int main()
{
    Entity *e;
    {
        Entity  *entity = new Entity("Project");
        e = entity;
        std::cout << entity->getName() << std::endl;
    }
    delete e;
    return (0);
}