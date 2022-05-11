#include <iostream>
#include <string>

class   Printable
{
public:
    virtual std::string getClassName() = 0;
};

class Entity : public Printable
{
public:
    virtual std::string GetName(){return  "Entity";}
    std::string getClassName(){return "Entity"; }   
};

class Player : public Entity
{
private:
    std::string m_name;
public:
     Player(const std::string &name)
        : m_name(name){}
    std::string GetName() {return m_name;} 
    std::string getClassName(){return "Player";}
};

class A : public Printable
{
    std::string  getClassName(){return "A";}
};

void    printName(Entity *e)
{
    std::cout <<  e->GetName() << std::endl;
}

void    Print(Printable *obj)
{
    std::cout << obj->getClassName() << std::endl;
}

int main()
{
    Entity  *e = new Entity();
    Player  *p = new Player("Project"); 
    Print(e);
    Print(p);
    Print(new A());
    printName(e);
    printName(p);
    return (0);
}